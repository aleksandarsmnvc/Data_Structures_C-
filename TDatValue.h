#ifndef T_DAT_VALUE
#define T_DAT_VALUE
class TDatValue {
 public:
 virtual TDatValue * GetCopy() =0; // создание копии
 ~TDatValue() {}
};
#endif