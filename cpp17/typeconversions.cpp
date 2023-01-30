//implicit conversions
// 1. integral types smaller than int will be promoted to larger integral type
// 2. conditions, non-bool expressions are converted to bool
// 3. initializations: initializer converted to variable type; assignment, right hand operand is converted to the left hand operand
// 4. arithmetic and relational expressions: operands with mixed type will be converted to a common one
// 5. function calls
// 6. conversion to const
// 7. Conversions defined by class type

// integral promotions
// bool ,char,signed char, unsigned char, short, unsigned short -> (unsigned) int
// larger chars: wchar_t, chart16_t, char32_t -> smallest type of (unsigend) int, (unsigned) long, (unsigned) long long

// arithmetic converions: operands converted to the widest type
// case of unsigned:
// 1. integration promotion happens first
// 2. if match, stop
// 3. if not match:
// 4.   if sign same: smaller type ->large type
// 5.   if sign diff: if unsigned operand >= signed operand, signd operand -> unsigned one
//                    if unsigned operand < signed operand: machine dependent
bool            flag;
short           sval;
int             ival;
long            lval;
float           fval;
char            cval;
unsigned short  usval;
unsigned int    uival;
unsigned long   ulval;
double          dval;

3.14159L + 'a'; // 'a' promoted to int,then that int converted to long double
dval + ival; // ival converted to double
dval + fval; // fval converted to double
ival = dval; // dval converted (by truncation) to int
flag = dval; // if dval is 0, then flag is false, otherwise true
cval + fval; // cval promoted to int, then that int converted to float
sval + cval; // sval and cval promoted to int

cval + lval; // cval converted to long
ival + ulval; // ival converted to unsigned long
usval + ival; // promotion depends on the size of unsigned short and int
uival + lval;// conversion depends on the size of unsigned int and long
