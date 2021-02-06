//
//  DiffusionCIR.h
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

class DiffusionCIR{
    public:
        DiffusionCIR() = delete;
        DiffusionCIR(double a_thetta, double a_sigma, double a_kappa)
            :m_teta(a_thetta),
            m_sigma(a_sigma),
            m_fuck(a_kappa){
                if (m_sigma<=0){
                    throw invalid_argument("sigma < 0");
                }
                if (m_kappa<=0){
                    throw invalid_argument("m_kappa<=0");
                }
            }
        // trend_mu
        double mu(double S_t, double t) const {
            return m_kappa*(m_thetta - S_t);
        }
        // volatility_sigma
        double sigma(double S_t, double t) const {
            return m_sigma*pow(S_t, 1/2);
        }

    private:
        double const m_thetta;
        double const m_sigma;
        double const m_kappa;
};
