# Electric Bell driver based on ATTINY13

## Requirements
* Drive 12V electric bell with ~100[Hz]
* the input signal goes from 24V sensor
* after 10 min inactivity input signals will give long bell
* after 10 sec inactivity input signals will give shott bell
* every avtivity before 10 sec will be ignored

## code
* avr-gcc with c++ 

## schematic


## Bill Of Materials
| C1         100n
| C2         100n
| C3         10u
| C4         100n
| D1         LED
| D2         DIODE
| IC1        ATTINY13-P
| L1         BELL 12V
| P1         CONN_2
| P2         CONN_2
| P3         CONN_6
| P4         CONN_2
| P5         CONN_2
| Q1         IRF530
| R1         3k3
| R2         100k
| R3         100k
| R4         1k
| R5         100
| SW1        SW_PUSH
| U1         LM7805CT
| U2         PHTRANS


