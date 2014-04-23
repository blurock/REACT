/*------------------------------------------*/
/*   Misc. Property Types   */
/* Structure:81:ArrheniusFormValue

                Aconstant --(FLOAT) The Arrhenius Constant
                   Energy --(FLOAT) The Activation Energy
                  TempExp --(FLOAT) The Temperature Exponent
           SymmetryFactor --(FLOAT) The Symmetry Factor
*/
typedef struct arrheniusformvalues ArrheniusFormValue;
struct arrheniusformvalues {
     INT ID;
     CHAR *Name;
     FLOAT  Aconstant;
     FLOAT  Energy;
     FLOAT  TempExp;
     FLOAT  SymmetryFactor;
     };
#define ArrheniusFormValueSize sizeof(ArrheniusFormValue)
#define AllocateArrheniusFormValue (ArrheniusFormValue *) Malloc(ArrheniusFormValueSize)
#define AllocArrayArrheniusFormValue(n) (ArrheniusFormValue *) Calloc(n,ArrheniusFormValueSize)
#define ArrheniusFormValuePntrSize sizeof(ArrheniusFormValue **)
#define AllocPntrArrayArrheniusFormValue(n) (ArrheniusFormValue **) Calloc(n,ArrheniusFormValuePntrSize)
#define SingCopyArrheniusFormValue(out,in) memcpy(out,in,ArrheniusFormValueSize)
extern ArrheniusFormValue *CreateArrheniusFormValue(ArrheniusFormValue *newstruct,
                                             INT id,
                                             CHAR *name,
                                             FLOAT  Aconstant,
                                             FLOAT  Energy,
                                             FLOAT  TempExp,
                                             FLOAT  SymmetryFactor);

extern CHAR *GetNameArrheniusFormValue(ArrheniusFormValue *str);
extern INT  GetIDArrheniusFormValue(ArrheniusFormValue *str);
extern void PrintArrheniusFormValue(ArrheniusFormValue *eleptr);
extern void FreeArrheniusFormValue(ArrheniusFormValue *eleptr);
extern void *AllocArrheniusFormValue();
extern void WriteBinArrheniusFormValue(ArrheniusFormValue *eleptr, DbaseLinkedList *file);
extern INT ReadBinArrheniusFormValue(ArrheniusFormValue *eleptr, DbaseLinkedList *file);
extern void xdr_ArrheniusFormValue(XDR *stream, char **eleptr);
extern void CopyFullArrheniusFormValue(ArrheniusFormValue *newstruct, ArrheniusFormValue *oldstruct);
