#ifndef TANH_LAYER_HPP
#define TANH_LAYER_HPP

#include <iostream>
#include <armadillo>

class TanhLayer
{
 public:
  TanhLayer(size_t inputHeight,
       size_t inputWidth,
       size_t inputDepth) :
      inputHeight(inputHeight),
      inputWidth(inputWidth),
      inputDepth(inputDepth)
  {
    // Nothing to do here.
  }

  void Forward(arma::cube& input, arma::cube& output)
  {
    
    //tanh
    output = arma::tanh(input);
    	  
    this->input = input;
    this->output = output;
  }

  void Backward(arma::cube upstreamGradient)
  {
    gradientWrtInput = input;

    gradientWrtInput.transform( [](double val) { return ( std::pow(std::cosh(val), -2)); });
    gradientWrtInput = gradientWrtInput % upstreamGradient;

  }

  arma::cube getGradientWrtInput() { return gradientWrtInput; }

 private:
  size_t inputHeight;
  size_t inputWidth;
  size_t inputDepth;

  arma::cube input;
  arma::cube output;

  arma::cube gradientWrtInput;
};

#endif
