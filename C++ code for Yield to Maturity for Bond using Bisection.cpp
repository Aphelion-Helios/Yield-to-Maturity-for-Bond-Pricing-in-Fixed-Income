#include <cmath> 

#include <iostream> 

using namespace std; 

 

double PVB(double Face,double cr,double r,int m, double T) 

{ 

    // store the value of the bond 

    double BV=0.; 

    // add in coupons 

    int TNC=T*m; 

    double cpn = (cr/m)*Face; 

    for(int i=1;i<=TNC; i++) 

	{ 

         

    	BV = BV + cpn*pow((1+r/m),-i); 

         

	} 

     

	BV = BV + Face*pow((1+r/m),-T*m); 

    return BV; 

} 

 

// Bisection Algorithm 

double BisecYTM(double Face, double cr, double Target, double T, int m, double a, double b) { 

 

    const int MaxIter = 50000; 

    double Tol = 0.0000001; 

    double midP = 0.0, midCdif; 

 

    double lowCdif = Target - PVB(Face, cr,a,  m,  T); 

    double highCdif = Target - PVB(Face, cr, b, m, T); 

    if (lowCdif*highCdif > 0) 

        return -1; 

    else 

        for (int i = 0; i <= MaxIter; i++) { 

    midP = (a + b) / 2.0; 

    midCdif = Target - PVB(Face,cr,midP,m,T); 

    if (abs(midCdif)<Tol) goto LastLine; 

    else { 

        if (midCdif>0) b = midP; 

            else a = midP; 

            	} 

    	} 

LastLine: 

return midP; 

} 

 

int main() 

{ 

    double Face = 1000; 

    double cr = 0.06; 

    double Target = 1010.91; 

    double T = 3; 

    int m = 2; 

    double a = 0.000001; 

    double b = 10; 

     

    double YTM = BisecYTM(Face,cr,Target,T, m,a,b); 

    cout << " YTM = " << YTM << " " << endl; 

     

} 