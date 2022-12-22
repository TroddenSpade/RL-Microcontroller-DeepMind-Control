import serial
import time
import gym
import numpy as np

RESPONSE_LENGTH = 100

arduino = serial.Serial(port='COM6', baudrate=115200)
time.sleep(1)

# Parallel environments
env = gym.make('CartPole-v1', render_mode="human")


def obs_to_str(obs):
    string = ""
    for i in obs:
        string += str(i) + " "
    return string[:-1]


def get_action():
    string = ""
    data = None
    while data != '\n':
        data = arduino.read().decode("utf-8")
        string += data

    nums = np.array([float(num) for num in string[:-1].split(" ")])
    print(nums)
    return np.argmax(nums)  


obs, info = env.reset()
arduino.write(obs_to_str(obs).encode())

while True:
    action = get_action()
    obs, reward, terminated, truncated, info = env.step(action)
    arduino.write(obs_to_str(obs).encode())

    if terminated or truncated:
        break
    env.render()

env.close()
