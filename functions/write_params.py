import os
import numpy as np

def write_params(name, model, params):
    with open(name, "a+") as f:
        b = 0
        w = 0
        shapes = []
        
        for name in params:
            p = model.state_dict().get(name).cpu().numpy()
            if len(p.shape)>1:
                var_name = f'w{w}'
                f.write(f"float {var_name}[{p.shape[0]}][{p.shape[1]}] = {{\n{{")
                np.savetxt(f, p, fmt='%.18e', delimiter=', ', newline='},\n{')
                f.seek(f.tell() - 1, os.SEEK_SET)
                f.truncate()
                w += 1
                shapes.append(p.shape[1])
            else:
                var_name = f'b{b}' 
                f.write(f"float {var_name}[{p.shape[0]}] = {{\n")
                np.savetxt(f, p, fmt='%.18e', delimiter=', ', newline=',\n')
                b += 1
            f.write("};\n\n")
        shapes.append(p.shape[0])

        f.write(f"int shape[{len(shapes)}] = {{")
        [f.write(f"{num},") for num in shapes]
        f.write("};\n")

        f.write(f"float *weights[{len(shapes)-1}] = {{")
        [f.write(f"w{num}[0],") for num in range(len(shapes)-1)]
        f.write("};\n")

        f.write(f"float *biases[{len(shapes)-1}] = {{")
        [f.write(f"b{num},") for num in range(len(shapes)-1)]
        f.write("};\n")