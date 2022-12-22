from email import policy
from functions.write_params import write_params

import torch
import gym
from stable_baselines3 import PPO
from stable_baselines3.common.env_util import make_vec_env

env = gym.make('CartPole-v1')

# policy_kwargs = dict(net_arch=[dict(pi=[12, 12], vf=[12, 12])])
# model = PPO("MlpPolicy", env, verbose=1, policy_kwargs=policy_kwargs)
# model.learn(total_timesteps=250000)
# model.save("ppo_cartpole")

# params = ["mlp_extractor.policy_net.0.weight", "mlp_extractor.policy_net.0.bias", "mlp_extractor.policy_net.2.weight", "mlp_extractor.policy_net.2.bias", "action_net.weight", "action_net.bias"]
# write_params("w.h", model.policy, params)

model = PPO.load("ppo_cartpole", env=env)

def forward(model, obs):
    with torch.no_grad():
        x = model.mlp_extractor.policy_net(obs)
        x = model.action_net(x)
    return x

def obs_to_str(obs):
    string = ""
    for i in obs:
        string += str(i) + " "
    return string[:-1]


rews = 0
obs, info = env.reset()
i = 0
while True:
    print(obs_to_str(obs))
    obs = torch.from_numpy(obs).unsqueeze(0).float()
    pi = forward(model.policy, obs)
    a1 = pi.argmax(dim=1).item()
    
    obs, reward, terminated, truncated, info = env.step(a1)
    rews += reward

    if terminated or truncated or (i > 100):
        break

print(rews)
env.close()