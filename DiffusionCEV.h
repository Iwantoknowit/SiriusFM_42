//
//  DiffusionCEV.h
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

class DiffusionCEV{
    public:
        DiffusionCEV() = delete;
        DiffusionCEV(double a_mu, double a_sigma, double a_beta)
            :m_mu(a_mu),
            m_sigma(a_sigma),
            m_beta(a_beta){
                if (m_sigma <= 0){
                    throw invalid_argument("sigma < 0");
                }
                if (m_beta <= 0 ){
                    throw invalid_argument("beta < 0");
                }
            }
        // trend_mu
        double mu(double S_t, double t) const {
            if (m_mu == 0) return 0
            return m_mu*S_t;
        }
        // volatility_sigma
        double sigma(double S_t, double t) const {
            return m_sigma*pow(S_t, m_beta);
        }

    private:
        double const m_mu;
        double const m_sigma;
        double const m_beta;
};
