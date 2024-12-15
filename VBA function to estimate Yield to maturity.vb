Function PVBmIRR(cpr, T, Face, m, Target)



Coup = Face * cpr / m

' PVBm = (Coup * (1 - (1 + r / m) ^ (-T * m)) / (r / m)) + Face * (1 + r / m) ^ (-T * m)



    H = 2

    L = 0

    Do While (H - L) > 0.0001

    If (Coup * (1 - (1 + ((H + L) / 2) / m) ^ (-T * m)) / (((H + L) / 2) / m)) + Face * (1 + ((H + L) / 2) / m) ^ (-T * m) > Target Then

    

             L = (H + L) / 2

             Else: H = (H + L) / 2

    End If

    Loop

    PVBmIRR = (H + L) / 2

    

End Function