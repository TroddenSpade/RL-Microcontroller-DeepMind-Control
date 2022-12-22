# Deep RL with Microcontrollers for DeepMind Control Tasks


## Requirements

* PyTorch
* [Arduino](https://www.arduino.cc)
* [Maixduino](https://maixduino.sipeed.com/en/)
* [DeepMind Control](https://github.com/deepmind/dm_control)
* [Mojuco-Py](https://github.com/openai/mujoco-py)

## Development Boards
### Arduino
- [x] Forward Pass
- [ ] Backpropagation
### Maixduino
- [ ] Forward Pass
- [ ] Backpropagation
    
## Environments
  - [x] CartPole
  - [ ] Acrobat
  - [ ] Cheetah
  - [ ] Hopper
  - [ ] Walker
  - [ ] Humanoid
  
## Gym Wrapper
Implemented a Gym Wrapper for the DeepMind Control Suit environments. You can observe their status in the table below.

| Mode | Task | Support |
| :-- | :----: | :-: |
|acrobot | swingup | ✔️ |
|acrobot | swingup_sparse | ✔️ |
|ball_in_cup | catch | ✔️ |
|cartpole | balance | ✔️ |
|cartpole | balance_sparse | ✔️ |
|cartpole | swingup | ✔️ |
|cartpole | swingup_sparse | ✔️ |
|cheetah | run | ✔️ |
|finger | spin | ✔️ |
|finger | turn_easy | ✔️ |
|finger | turn_hard | ✔️ |
|fish | upright | ✔️ |
|fish | swim | ✔️ |
|hopper | stand | ✔️ |
|hopper | hop | ✔️ |
|humanoid | stand | ✔️ |
|humanoid | walk | ✔️ |
|humanoid | run | ✔️ |
|manipulator | bring_ball | ❌ |
|pendulum | swingup | ✔️ |
|point_mass | easy | ✔️ |
|reacher | easy | ✔️ |
|reacher | hard | ✔️ |
|swimmer | swimmer6 | ✔️ |
|swimmer | swimmer15 | ✔️ |
|walker | stand | ✔️ |
|walker | walk | ✔️ |
|walker | run | ✔️ |


## Experiments
### MuJoCo CartPole Test

https://user-images.githubusercontent.com/33734646/209011882-17eb2b25-35c9-439b-8df8-f64e698ea088.mp4

https://user-images.githubusercontent.com/33734646/209122011-977ab6bd-e6ac-4a0e-b924-622d85ec4fd5.mp4



### CartPole Environment

https://user-images.githubusercontent.com/33734646/209012407-4a1bd432-ecf5-455a-9f36-179bf7b36f93.mp4


### Ball in Cup Environment

https://user-images.githubusercontent.com/33734646/209012545-4b430209-72a3-4150-83a6-017390e7bf35.mp4



## References

1. 
