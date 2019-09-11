## CPP-CNN

A C++ implementation of the popular LeNet convolutional neural network architecture. Currently it trains on the Kaggle Digit Recognizer challenge data.

### Prerequisites for building and running the model

You'll probably need
- g++ >= 5.0.0
sudo apt-get install gcc

- CMake >= 3.0.0
sudo apt-get install cmake

- make >= 4.0
sudo apt-get install make

- Armadillo >= 8.300.4
sudo apt-get install libarmadillo-dev

- Boost unit test framework (Boost version >= 1.58)
sudo apt-get install liblapack-dev
sudo apt-get install libblas-dev
sudo apt-get install libboost-dev

to run everything in this repo. I've only tried to run this on a Linux system (VM, Ubuntu 18.04, RAM: 4G) -- but I dont see any obvious reason why it shouldn't work on other platforms as long as you have the dependencies installed.

You will also need the Kaggle Digit recognizer dataset - which can be downloaded from [here](https://www.kaggle.com/c/digit-recognizer/data)

### Building and Running the LeNet on the Digit Recognizer dataset

1. Clone this repository. `git clone https://github.com/plantsandbuildings/cpp-cnn`
2. `cd` into the project root (`cd cpp-cnn`) and create the build and data directories using `mkdir build data`.
3. Copy the Kaggle Digit Recognizer dataset into the `data` directory. The `data` directory should now contain two CSV files -- `train.csv` and `test.csv`.
4. `cd` into the build directory (`cd build`) and configure the build using `cmake ../` This will generate a `Makefile` to build the project.
5. Run `make` to build the project. Binaries are written to `build/bin`.
6. Train the model on the Kaggle data using `bin/le_net`.

The program will write the test predictions after each epoch of training into CSV files - `build/results_epoch_1.csv`, `build/results_epoch_2.csv` etc. These files can directly be uploaded to the [submission page](https://www.kaggle.com/c/digit-recognizer/submit) on Kaggle to view the scores.
