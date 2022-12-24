from dm_control import suite
from wrappers.DMControlGym import DeepMindControlGym

max_len = max(len(d) for d, _ in suite.BENCHMARKING)
max_len2 = max(len(d) for _, d in suite.BENCHMARKING)

for domain, task in suite.BENCHMARKING:
    try:
        env = DeepMindControlGym(domain=domain, task=task)
        env.reset()
        env.step(env.action_space.sample())
        print(f'{domain:<{max_len}}  {task:<{max_len2}} [Works]')
    except ValueError:
        print(f'{domain:<{max_len}}  {task:<{max_len2}} [Does not Work]')