//
//  DiffusionLIP.h
//  Sirius
//
//  Created by Кирилл Мосиевич on 05.02.2021.
//
#pragma once /* Защита от двойного подключения заголовочного файла */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class DiffusionLIP{
    public:
        DiffusionLIP() = delete;
        DiffusionLIP(double a_mu, double a_sigma_0, double a_sigma_1, double a_sigma_2)
            :m_mu(a_mu),
            m_sigma_0(a_sigma_0),
            m_sigma_1(a_sigma_1),
            m_sigma_2(a_sigma_2)
            {
                if (m_sigma_0<=0){
                    throw invalid_argument("sigma_0 < 0");
                }
                if (m_sigma_1<=0){
                    throw invalid_argument("sigma_1 < 0");
                }
                if (m_sigma_2<=0){
                    throw invalid_argument("sigma_2 < 0");
                }
            }
        // trend_mu
        double mu(double S_t, double t) const {
            if (m_mu == 0) return 0
            return m_mu*S_t;
        }
        // volatility_sigma
        double sigma(double S_t, double t) const {
            return m_sigma_0 + m_sigma_1*S_t + m_sigma_2*pow(S_t, 2);
        }

    private:
        double const m_mu;
        double const m_sigma_0;
        double const m_sigma_1;
        double const m_sigma_2;
};
