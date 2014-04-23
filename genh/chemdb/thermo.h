/*------------------------------------------*/
/*   Thermodyanic Database Structures   */
/* Structure:100:BensonTables

              SecondOrder --(BensonSecondOrderTable) The Table of Second Order Bond Values
               BensonTree --(BensonCalculation) The Table Values in Tree form
              Translation --(SetOfBensonAtomTranslationPairs) The corresponding translation table
*/
typedef struct bensontables BensonTables;
struct bensontables {
     INT ID;
     CHAR *Name;
     BensonSecondOrderTable *SecondOrder;
     BensonCalculation *BensonTree;
     SetOfBensonAtomTranslationPairs *Translation;
     };
#define BensonTablesSize sizeof(BensonTables)
#define AllocateBensonTables (BensonTables *) Malloc(BensonTablesSize)
#define AllocArrayBensonTables(n) (BensonTables *) Calloc(n,BensonTablesSize)
#define BensonTablesPntrSize sizeof(BensonTables **)
#define AllocPntrArrayBensonTables(n) (BensonTables **) Calloc(n,BensonTablesPntrSize)
#define SingCopyBensonTables(out,in) memcpy(out,in,BensonTablesSize)
extern BensonTables *CreateBensonTables(BensonTables *newstruct,
                                 INT id,
                                 CHAR *name,
                                 BensonSecondOrderTable *SecondOrder,
                                 BensonCalculation *BensonTree,
                                 SetOfBensonAtomTranslationPairs *Translation);

extern CHAR *GetNameBensonTables(BensonTables *str);
extern INT  GetIDBensonTables(BensonTables *str);
extern void PrintBensonTables(BensonTables *eleptr);
extern void FreeBensonTables(BensonTables *eleptr);
extern void *AllocBensonTables();
extern void WriteBinBensonTables(BensonTables *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonTables(BensonTables *eleptr, DbaseLinkedList *file);
extern void xdr_BensonTables(XDR *stream, char **eleptr);
extern void CopyFullBensonTables(BensonTables *newstruct, BensonTables *oldstruct);
