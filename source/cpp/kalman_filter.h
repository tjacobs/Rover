#ifndef MODEL_EKF_H_
#define MODEL_EKF_H_
#include <eigen3/Eigen/Dense>

// This file is auto-generated by ekf/codegen.py.

class EKF {
 public:
  EKF();
  
  void Reset();

  void Predict(float Delta_t, float u_M, float u_delta);
  bool UpdateCenterline(float a, float b, float c, float y_c, Eigen::MatrixXf Rk);
  bool UpdateIMU(float g_z);
  bool UpdateEncoders(float dsdt, float fb_delta);

  Eigen::VectorXf& GetState() { return x_; }
  Eigen::MatrixXf& GetCovariance() { return P_; }

 private:
  Eigen::VectorXf x_;
  Eigen::MatrixXf P_;
};

#endif  // MODEL_EKF_H_

