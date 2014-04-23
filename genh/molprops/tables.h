/*------------------------------------------*/
/*   Structures for Current Thermodynamic Tables (As Read In and transformed)   */
/* Structure:100:SetOfTables

            ChemkinThermo --(SetOfChemkinThermoInformation) The Chemkin Thermodynamic Table
              SecondOrder --(SetOfBenson2ndOrderTables) Set of Benson 2nd Order Tables
         AtomTranslations --(SetOfBensonAtomTranslationPairs) Set of translations of benson atom strings
               BensonTree --(BensonCalculation) The transformed Benson Tables
*/
typedef struct setofthermotables SetOfTables;
struct setofthermotables {
     INT ID;
     CHAR *Name;
     SetOfChemkinThermoInformation *ChemkinThermo;
     SetOfBenson2ndOrderTables *SecondOrder;
     SetOfBensonAtomTranslationPairs *AtomTranslations;
     BensonCalculation *BensonTree;
     };
#define SetOfTablesSize sizeof(SetOfTables)
#define AllocateSetOfTables (SetOfTables *) Malloc(SetOfTablesSize)
#define AllocArraySetOfTables(n) (SetOfTables *) Calloc(n,SetOfTablesSize)
#define SetOfTablesPntrSize sizeof(SetOfTables **)
#define AllocPntrArraySetOfTables(n) (SetOfTables **) Calloc(n,SetOfTablesPntrSize)
#define SingCopySetOfTables(out,in) memcpy(out,in,SetOfTablesSize)
extern SetOfTables *CreateSetOfTables(SetOfTables *newstruct,
                               INT id,
                               CHAR *name,
                               SetOfChemkinThermoInformation *ChemkinThermo,
                               SetOfBenson2ndOrderTables *SecondOrder,
                               SetOfBensonAtomTranslationPairs *AtomTranslations,
                               BensonCalculation *BensonTree);

extern CHAR *GetNameSetOfTables(SetOfTables *str);
extern INT  GetIDSetOfTables(SetOfTables *str);
extern void PrintSetOfTables(SetOfTables *eleptr);
extern void FreeSetOfTables(SetOfTables *eleptr);
extern void *AllocSetOfTables();
extern void WriteBinSetOfTables(SetOfTables *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfTables(SetOfTables *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfTables(XDR *stream, char **eleptr);
extern void CopyFullSetOfTables(SetOfTables *newstruct, SetOfTables *oldstruct);
