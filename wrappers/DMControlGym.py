import gym
import numpy as np
from dm_control import suite

class DeepMindControlGym(gym.Env):

    def __init__(self, domain, task):
        self.env = suite.load(domain_name=domain, task_name=task)

        action_spec = self.env.action_spec()
        observation_spec = self.env.observation_spec()
        self.obs_keys = list(observation_spec.keys())

        self.observation_space = gym.spaces.Box(low=-np.inf, 
                                                high=np.inf,
                                                shape=(sum([v.shape[0] for v in observation_spec.values() if len(v.shape)>0]),),
                                                dtype=np.float32)

        self.action_space = gym.spaces.Box(low=action_spec.minimum, 
                                           high=action_spec.maximum,
                                           shape=action_spec.shape,
                                           dtype=np.float32)


    def obs_(self, obs):
        return np.concatenate([v for v in obs.values() if len(v.shape)>0], dtype=np.float32)


    def reset(self):
        time_step = self.env.reset()
        return self.obs_(time_step.observation), {"discount":time_step.discount}


    def step(self, action):
        time_step = self.env.step(action)
        return self.obs_(time_step.observation), time_step.reward, time_step.last(), time_step.last(), {"discount":time_step.discount}
        