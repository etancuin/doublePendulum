//
//  double_pendulum.cpp
//  DoublePendulum
//
//  Created by Ethan Quinn on 3/14/23.
//

#include "double_pendulum.hpp"

pendulum::pendulum(std::pair<float, float> _length, std::pair<float, float> _theta, std::pair<float, float> _omega,
                   std::pair<float, float> _mass)
{
    length = _length;
    theta = _theta;
    omega = _omega;
    mass = _mass;
    dydxTheta = {0.0f, 0.0f};
    dydxOmega = {0.0f, 0.0f};
    xCoordinate.first = (length.first * sin(theta.first));
    yCoordinate.first = -(length.first * cos(theta.first));
    xCoordinate.second = xCoordinate.first + (length.second * sin(theta.second));
    yCoordinate.second = yCoordinate.first - (length.second * cos(theta.second));
    xEndpoints.push_back(xCoordinate.second);
    yEndpoints.push_back(yCoordinate.second);
}
void pendulum::update()
{
    float delta = theta.second - theta.first;
    float totalMass = mass.first + mass.second;
    float denominator = totalMass * mass.first - mass.second * mass.first * cos(delta) * cos(delta);
    
    dydxTheta.first = omega.first;
    dydxOmega.first = (mass.second * mass.first * omega.first * omega.first * sin(delta) * cos(delta) + mass.second * GRAVITY * sin(theta.second) * cos(delta) + mass.second * mass.second * omega.second * omega.second *sin(delta) - totalMass * GRAVITY * sin(theta.first)) / denominator;
    dydxTheta.second = omega.second;
    
    denominator *= mass.second / mass.first;
    dydxOmega.second = (-mass.second * mass.second * omega.second * omega.second * sin(delta) * cos(delta) + totalMass * GRAVITY * sin(theta.first) * cos(delta) - totalMass * mass.first * omega.first * omega.first * sin(delta) - totalMass * GRAVITY * sin(theta.second)) / denominator;
    
    theta.first = theta.first + dydxTheta.first * DT;
    omega.first = omega.first + dydxOmega.first * DT;
    xCoordinate.first = (length.first * sin(theta.first));
    yCoordinate.first = -(length.first * cos(theta.first));
    std::cout << "(" << xCoordinate.first << ", " << yCoordinate.first << ")" << std::endl;
    
    theta.second = theta.second + dydxTheta.second * DT;
    omega.second = omega.second + dydxOmega.second * DT;
    xCoordinate.second = xCoordinate.first + (length.second * sin(theta.second));
    yCoordinate.second = yCoordinate.first - (length.second * cos(theta.second));
    std::cout << "(" << xCoordinate.second << ", " << yCoordinate.second << ")" << std::endl;
    xEndpoints.push_back(xCoordinate.second);
    yEndpoints.push_back(yCoordinate.second);
}
void pendulum::print()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Double Pendulum");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        this->update();
        window.clear();
      
        sf::RectangleShape bob1(sf::Vector2f(length.first, 3));
        bob1.setPosition(500, 500);
        bob1.rotate(fabs(theta.first - PI / 2) * (180 / PI));
        window.draw(bob1);
        
        sf::CircleShape node1(4);
        node1.setPosition(xCoordinate.first + 496, yCoordinate.first + 496);
        window.draw(node1);
        
        sf::RectangleShape bob2(sf::Vector2f(length.second, 3));
        bob2.setPosition(xCoordinate.first + 500, yCoordinate.first + 500);
        bob2.rotate(fabs(theta.second - PI / 2) * (180 / PI));
        window.draw(bob2);
        
        sf::CircleShape node2(4);
        node1.setPosition(xCoordinate.second + 496, yCoordinate.second + 496);
        window.draw(node2);
        
        for(int i = 0; i < xEndpoints.size(); i++)
        {
            
            sf::RectangleShape point(sf::Vector2f(2, 2));
            point.setPosition(xEndpoints.at(i) + 500, yEndpoints.at(i) + 500);
            window.draw(point);
        }
        window.display();
    }
}
