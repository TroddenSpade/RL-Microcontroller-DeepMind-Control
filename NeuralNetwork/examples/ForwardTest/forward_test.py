import torch
import serial
import time
import numpy as np
from tqdm import tqdm

arduino = serial.Serial(port='COM9', baudrate=115200)
time.sleep(1)

def read_serial():
    string = ""
    data = None
    while data != '\n':
        data = arduino.read().decode("utf-8")
        string += data
    return string


print(read_serial())

model = torch.nn.Sequential(
    torch.nn.Linear(5, 32),
    torch.nn.Tanh(),
    torch.nn.Linear(32, 2),
)

inputs = np.random.randn(5, 5)
for p in tqdm(inputs.flatten()):
    arduino.write(("%.10e"%(p)).encode())
    read_serial()
    

inputs = torch.from_numpy(inputs).type(torch.float32)

outputs = model(inputs).detach().numpy()

print(read_serial())
parameters = list(model.named_parameters())[::2] + list(model.named_parameters())[1::2]
for name, params in parameters:
    print("Sending ", name)
    for p in tqdm(params.flatten().detach().numpy()):
        arduino.write(("%.10e"%(p)).encode())
        read_serial()

print(read_serial())

print("Inputs: ", inputs)
print("Outputs: ", outputs)
arduino.write(('\n').encode())

print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())
print(read_serial())