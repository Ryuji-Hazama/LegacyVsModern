 *ORDFRING OF DATA
        LDA     N
        DCR     A
        MOV     C,A
        LXI     D,DATA-1
INCJ    INX     D
        MOV     B,C
        MOV     L,E
        MOV     H,D
INCI    INX     H
        LDAX    D
        CMP     M
        JM      SKIP
        MOV     A,B
        STA     WS
        LDAX    D
        MOV     B,M
        XCHG
        STAX    D
        MOV     M,B
        XCHG
        LDA     WS
        MOV     B,A
SKIP    DCR     B
        JNZ     INCI
        DCR     C
        JNZ     INCJ
        HLT
WS      DS      1
NOP     DB      5
DATA    DB      9,6,13,-5,4
        END