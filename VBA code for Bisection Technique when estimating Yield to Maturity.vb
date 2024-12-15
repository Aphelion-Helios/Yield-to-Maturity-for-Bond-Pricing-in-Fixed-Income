' PV of Bond using PV of Annuity  

Function PVBm(cpr, r, T, Face, m)  

coup = Face * cpr / m  

  

PVBm = (coup * (1 - (1 + r / m) ^ (-T * m)) / (r / m)) + Face * (1 + r / m) ^ (-T * m)  

End Function  

  

' YTM of Bond using Bisection  

Function PVBmIRR(cpr, T, Face, m, Target)  

    H = 2  

    L = 0  

    Do While (H - L) > 0.0001  

    If PVBm(cpr, ((H + L) / 2), T, Face, m) > Target Then  

      

             L = (H + L) / 2  

             Else: H = (H + L) / 2  

    End If  

    Loop  

    PVBmIRR = (H + L) / 2  

End Function   