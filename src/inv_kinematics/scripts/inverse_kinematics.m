function [j1, j2, j3, j4, j5, j6] = inverse_kinematics(x, y, z, a, b, c)
%INVERSE_KINEMATICS Inverse kinematics of 6DOF Mover6 Manipulator
%   a - yaw
%   b - pitch
%   c - roll

mover6 = importrobot('CPMOVER6.urdf');



a_tform = [cos(a) -sin(a) 0 0;
           sin(a) cos(a) 0 0;
           0 0 1 0;
           0 0 0 1];

b_tform = [cos(b) 0 sin(b) 0;
           0 1 0 0;
           -sin(b) 0 cos(b) 0;
           0 0 0 1];

c_tform = [1 0 0 0;
           0 cos(c) -sin(c) 0;
           0 sin(c) cos(c) 0;
           0 0 0 1];

abc_tform = a_tform*b_tform*c_tform;

xyz_tform = [1 0 0 x; 0 1 0 y; 0 0 1 z; 0 0 0 1];

tform = abc_tform*xyz_tform;

ik = inverseKinematics('RigidBodyTree', mover6);
ik.SolverParameters

weights = [0.25 0.25 0.25 1 1 1];

initialGuess = mover6.homeConfiguration;

[configSoln, solnInfo] = ik('link6', tform, weights, initialGuess);

show(mover6, configSoln)

[j1, j2, j3, j4, j5, j6] = configSoln.JointPosition;

end

