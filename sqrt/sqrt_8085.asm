 *SQUARE ROOT OF 1 BYTE INTEGER
 *SUBROUTINE  SQRT
        ORG     /500
SQRT    XRA     A
        ORA     L
        JP      SQR1
        HLT
SQR1    JNZ     SQR2
        MOV     D,L
        RET
SQR2    MOV     D,L
SQR3    MOV     C,L
        CALL    DIV1
        XRA     A
        MOV     A,C
        ADD     D
        RAR
        CMP     D
        MOV     D,A
        JNZ     SQR3
        RET
 *SUBROUTINE  DIV1
DIV1    XRA     A
        ORA     D
        JNZ     DV11
        HLT
DV11    MVI     B,0
        MVI     E,8
DV12    XRA     A
        MOV     A,C
        RAL
        MOV     C,A
        MOV     A,B
        RAL
        MOV     B,A
        SUB     D
        JM      DV13
        MOV     B,A
        INR     C
DV13    DCR     E
        JNZ     DV12
        RET
 *TEST  SQRT
MNSP    EQU     /1F7E
MNTR    EQU     0
        LXI     S,MNSP
        MVI     L,5
        CALL    SQRT
        LXI     H,WS
        MOV     M,D
        JMP     MNTR
WS      DS      1
        END