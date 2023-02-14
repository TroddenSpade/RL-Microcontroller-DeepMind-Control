import serial
import time
import gym
import numpy as np

RESPONSE_LENGTH = 100

arduino = serial.Serial(port='COM9', baudrate=115200)
time.sleep(0.1)

# Parallel environments
env = gym.make('CartPole-v1')


def obs_to_str(obs, reward, terminated):
    string = ""
    for i in obs:
        string += str(i) + " "
    string = string[:-1] + ";" + str(reward) + ";" + str(int(terminated))
    return string


def get_response():
    string = ""
    data = None
    while data != '\n':
        data = arduino.read().decode("utf-8")
        string += data
    return string[:-1]


def get_action():
    string = get_response()

    nums = np.array([float(num) for num in string.split(" ")])
    return np.argmax(nums)


# connected to wifi
s1 = get_response()
print(s1)
# connected to server
s2 = get_response()
print(s2)


obs = env.reset()
arduino.write(obs_to_str(obs, 0.0, 0).encode())
print("Sent: ", obs_to_str(obs, 0.0, 0))

while True:
    action = get_action()
    print("RECV: ", action)
    time.sleep(1)
    obs, reward, terminated, info = env.step(action)
    arduino.write(obs_to_str(obs, reward, terminated).encode())

    print("Sent: ", obs_to_str(obs, 0.0, 0))

    if terminated:
        break
    # env.render()

env.close()
