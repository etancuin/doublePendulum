//
//  main.cpp
//  DoublePendulum
//
//  Created by Ethan Quinn on 3/14/23.
//

#include "double_pendulum.hpp"

int main(int argc, const char * argv[]) {
    float temp1, temp2;
    std::pair<float, float> length, theta, omega, mass;

    std::cout << "Enter upper and lower pendulum length [1, 5]:" << std::endl << ">. ";
    std::cin >> temp1 >> temp2;
    length.first = temp1;
    length.second = temp2;
    
    std::cout << "Enter initial upper and lower pendulum angle [radians]:" << std::endl << ">. ";
    std::cin >> temp1 >> temp2;
    theta.first = temp1;
    theta.second = temp2;
    
    std::cout << "Enter initial upper and lower pendulum angular velocity [radians per second]:" << std::endl << ">. ";
    std::cin >> temp1 >> temp2;
    omega.first = temp1;
    omega.second = temp2;
    
    std::cout << "Enter upper and lower pendulum mass:" << std::endl << ">. ";
    std::cin >> temp1 >> temp2;
    mass.first = temp1;
    mass.second = temp2;
    
    pendulum doublePendulum(length, theta, omega, mass);
    doublePendulum.print();
    
    return 0;
}
