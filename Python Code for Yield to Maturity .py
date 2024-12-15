def bonds_price_discrete(times, cashflows, r):

    

    p = 0   

    for i in range(len(times)):

        p += cashflows[i] / np.power((1 + r), times[i])        

    return p



def bond_yield_to_maturity_discrete(times, cashflows, bondprice):

    

    ACCURACY = 1e-5

    MAX_ITERATIONS = 200

    bot = 0

    top = 1.

    

    while bonds_price_discrete(times, cashflows, top) > bondprice: 

        top = top * 2

        

    r = .5 * (top + bot)

    

    for _ in range(MAX_ITERATIONS):

        diff = bonds_price_discrete(times, cashflows, r) - bondprice

        

        if np.abs(diff) < ACCURACY:

            return r

        if diff > 0:

            bot = r           

        else:

            top = r           

        r = .5 * (top + bot)     

    return r

    

import numpy as np 



c = np.array([60, 60, 1060])

t = np.arange(1, 4)

r = .056

b = np.sum(c * (1. / np.power((1 + r), t)))

print('Bond price, 5.6% percent discretely compounded interest = {:.3f}'.format(

        bonds_price_discrete(t, c, r)))



print('bond yield to maturity = {:.4f}'.format(bond_yield_to_maturity_discrete(t, c, b)))