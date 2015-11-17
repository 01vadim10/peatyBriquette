(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG 120
 ********************************************************************
 * Library: Operator
 * File: Operator.fun
 * Created: 11.11.2003
 ********************************************************************
 * Functions and function blocks of library Operator
 ********************************************************************)
FUNCTION SIZEOF : UDINT (* Return size of a variable in memory *)
	VAR_INPUT
		in	:ANY;
	END_VAR
END_FUNCTION
FUNCTION ADR : UDINT (* Return address of a variable in memory *)
	VAR_INPUT
		in	:ANY;
	END_VAR
END_FUNCTION
FUNCTION SHR : ANY (* IEC1131-3: OUT := IN right-shifted by N bits, zero-filled left *)
	VAR_INPUT
		IN	:ANY;
		N	:SINT;
	END_VAR
END_FUNCTION
FUNCTION ROR : ANY (* IEC1131-3: OUT := IN right-rotated by N bits, circular *)
	VAR_INPUT
		IN	:ANY;
		N	:SINT;
	END_VAR
END_FUNCTION
FUNCTION ROL : ANY (* IEC1131-3: OUT := IN left-rotated by N bits, circular *)
	VAR_INPUT
		IN	:ANY;
		N	:SINT;
	END_VAR
END_FUNCTION
FUNCTION SHL : ANY (* IEC1131-3: OUT := IN left-shifted by N bits, zero-filled right *)
	VAR_INPUT
		IN	:ANY;
		N	:SINT;
	END_VAR
END_FUNCTION
FUNCTION AND : ANY (* IEC1131-3: OUT := IN1 & IN2 & ... & INn *)
	VAR_INPUT
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION XOR : ANY (* IEC1131-3: OUT := IN1 XOR IN2 XOR ... XOR INn *)
	VAR_INPUT
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION OR : ANY (* IEC1131-3: OUT := IN1 OR IN2 OR ... OR INn *)
	VAR_INPUT
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION NOT : ANY (* IEC1131-3: OUT := NOT IN *)
	VAR_INPUT
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION ADD : ANY (* IEC1131-3: OUT := IN1 + IN2 + ... + INn *)
	VAR_INPUT
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION MUL : ANY_NUM (* IEC1131-3: OUT := IN1 * IN2 * ... * INn *)
	VAR_INPUT
		INx	:ANY_NUM;
	END_VAR
END_FUNCTION
FUNCTION SUB : ANY (* IEC1131-3: OUT := IN1 - IN2 *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION DIV : ANY_NUM (* IEC1131-3: OUT := IN1 / IN2 *)
	VAR_INPUT
		IN1	:ANY_NUM;
		IN2	:ANY_NUM;
	END_VAR
END_FUNCTION
FUNCTION MOD : ANY_INT (* IEC1131-3: OUT := IN1 modulo IN2 *)
	VAR_INPUT
		IN1	:ANY_INT;
		IN2	:ANY_INT;
	END_VAR
END_FUNCTION
FUNCTION MOVE : ANY (* IEC1131-3: OUT := IN *)
	VAR_INPUT
		IN	:ANY;
	END_VAR
END_FUNCTION
FUNCTION MAX : ANY (* IEC1131-3: OUT := MAX(IN1, IN2) *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION MIN : ANY (* IEC1131-3: OUT := MIN(IN1, IN2) *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION LIMIT : ANY (* IEC1131-3: OUT := MIN(MAX(IN,MN),MX) *)
	VAR_INPUT
		MN	:ANY;
		IN	:ANY;
		MX	:ANY;
	END_VAR
END_FUNCTION
FUNCTION SEL : ANY (* IEC1131-3: OUT := IN0 if G = 0; OUT := IN1 if G = 1 *)
	VAR_INPUT
		G	:BOOL;
		IN0	:ANY;
		IN1	:ANY;
	END_VAR
END_FUNCTION
FUNCTION MUX : ANY (* IEC1131-3: Select one of "N" inputs  depending on input K *)
	VAR_INPUT
		K	:SINT;
		INx	:ANY;
	END_VAR
END_FUNCTION
FUNCTION GE : BOOL (* IEC1131-3: OUT := (IN1>=IN2)  *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION EQ : BOOL (* IEC1131-3: OUT := (IN1=IN2)  *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION GT : BOOL (* IEC1131-3: OUT := (IN1>IN2)  *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION LE : BOOL (* IEC1131-3: OUT := (IN1<=IN2)  *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION LT : BOOL (* IEC1131-3: OUT := (IN1<IN2)  *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION NE : BOOL (* IEC1131-3: OUT := (IN1<>IN2) *)
	VAR_INPUT
		IN1	:ANY;
		IN2	:ANY;
	END_VAR
END_FUNCTION
FUNCTION ABS : ANY_NUM (* IEC1131-3: Absolute value *)
	VAR_INPUT
		IN	:ANY_NUM;
	END_VAR
END_FUNCTION
FUNCTION SQRT : ANY_REAL (* IEC1131-3: Square root *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION LN : ANY_REAL (* IEC1131-3: Natural logarithm *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION LOG : ANY_REAL (* IEC1131-3: Logarithm base 10 *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION EXP : ANY_REAL (* IEC1131-3: Natural exponential *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION SIN : ANY_REAL (* IEC1131-3: Sine of input in radians *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION COS : ANY_REAL (* IEC1131-3: Cosine in radians *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION TAN : ANY_REAL (* IEC1131-3: Tangent in radians *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION ASIN : ANY_REAL (* IEC1131-3: Principal arc sine *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION ACOS : ANY_REAL (* IEC1131-3: Principal arc cosine *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION ATAN : ANY_REAL (* IEC1131-3: Principal arc tangent *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION
FUNCTION EXPT : REAL (* IEC1131-3: Exponentiation: OUT := IN1 ^ IN2 *)
	VAR_INPUT
		IN1	:REAL;
		IN2	:ANY_NUM;
	END_VAR
END_FUNCTION
FUNCTION TRUNC : INT (* IEC1131-3: Truncation toward zero *)
	VAR_INPUT
		IN	:ANY_REAL;
	END_VAR
END_FUNCTION