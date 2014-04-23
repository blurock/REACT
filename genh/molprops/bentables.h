/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:100:BensonAtomConnections

                  Valence --(INT) The Atom Valence Value
             Multiplicity --(INT) The Multiplicity
*/
typedef struct bensonatomconnections BensonAtomConnections;
struct bensonatomconnections {
     INT ID;
     CHAR *Name;
     INT  Valence;
     INT  Multiplicity;
     };
#define BensonAtomConnectionsSize sizeof(BensonAtomConnections)
#define AllocateBensonAtomConnections (BensonAtomConnections *) Malloc(BensonAtomConnectionsSize)
#define AllocArrayBensonAtomConnections(n) (BensonAtomConnections *) Calloc(n,BensonAtomConnectionsSize)
#define BensonAtomConnectionsPntrSize sizeof(BensonAtomConnections **)
#define AllocPntrArrayBensonAtomConnections(n) (BensonAtomConnections **) Calloc(n,BensonAtomConnectionsPntrSize)
#define SingCopyBensonAtomConnections(out,in) memcpy(out,in,BensonAtomConnectionsSize)
extern BensonAtomConnections *CreateBensonAtomConnections(BensonAtomConnections *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Valence,
                                                   INT  Multiplicity);

extern CHAR *GetNameBensonAtomConnections(BensonAtomConnections *str);
extern INT  GetIDBensonAtomConnections(BensonAtomConnections *str);
extern void PrintBensonAtomConnections(BensonAtomConnections *eleptr);
extern void FreeBensonAtomConnections(BensonAtomConnections *eleptr);
extern void *AllocBensonAtomConnections();
extern void WriteBinBensonAtomConnections(BensonAtomConnections *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonAtomConnections(BensonAtomConnections *eleptr, DbaseLinkedList *file);
extern void xdr_BensonAtomConnections(XDR *stream, char **eleptr);
extern void CopyFullBensonAtomConnections(BensonAtomConnections *newstruct, BensonAtomConnections *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:101:BensonSecondThermoTable

          HeatOfFormation --(FLOAT) Heat Of Formation
                  Entropy --(FLOAT) Entropy
     NumberOfHeatCapacityValues --(INT) The number of heat capacity values
       HeatCapacityValues --(FLOAT) The set of Values
*/
typedef struct bensonsecondthermotable BensonSecondThermoTable;
struct bensonsecondthermotable {
     INT ID;
     CHAR *Name;
     FLOAT  HeatOfFormation;
     FLOAT  Entropy;
     INT  NumberOfHeatCapacityValues;
     FLOAT *HeatCapacityValues;
     };
#define BensonSecondThermoTableSize sizeof(BensonSecondThermoTable)
#define AllocateBensonSecondThermoTable (BensonSecondThermoTable *) Malloc(BensonSecondThermoTableSize)
#define AllocArrayBensonSecondThermoTable(n) (BensonSecondThermoTable *) Calloc(n,BensonSecondThermoTableSize)
#define BensonSecondThermoTablePntrSize sizeof(BensonSecondThermoTable **)
#define AllocPntrArrayBensonSecondThermoTable(n) (BensonSecondThermoTable **) Calloc(n,BensonSecondThermoTablePntrSize)
#define SingCopyBensonSecondThermoTable(out,in) memcpy(out,in,BensonSecondThermoTableSize)
extern BensonSecondThermoTable *CreateBensonSecondThermoTable(BensonSecondThermoTable *newstruct,
INT id,
CHAR *name,
FLOAT  HeatOfFormation,
FLOAT  Entropy,
INT  NumberOfHeatCapacityValues,
FLOAT *HeatCapacityValues);

extern CHAR *GetNameBensonSecondThermoTable(BensonSecondThermoTable *str);
extern INT  GetIDBensonSecondThermoTable(BensonSecondThermoTable *str);
extern void PrintBensonSecondThermoTable(BensonSecondThermoTable *eleptr);
extern void FreeBensonSecondThermoTable(BensonSecondThermoTable *eleptr);
extern void *AllocBensonSecondThermoTable();
extern void WriteBinBensonSecondThermoTable(BensonSecondThermoTable *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonSecondThermoTable(BensonSecondThermoTable *eleptr, DbaseLinkedList *file);
extern void xdr_BensonSecondThermoTable(XDR *stream, char **eleptr);
extern void CopyFullBensonSecondThermoTable(BensonSecondThermoTable *newstruct, BensonSecondThermoTable *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:102:BensonSecondOrder

               CenterAtom --(INT) The Center Atom Valence
      NumberOfConnections --(INT) The number of Types Connected
              Connections --(BensonAtomConnections) The set of Connection Types
              TableValues --(BensonSecondThermoTable) The thermodynamic information
*/
typedef struct bensonsecondorder BensonSecondOrder;
struct bensonsecondorder {
     INT ID;
     CHAR *Name;
     INT  CenterAtom;
     INT  NumberOfConnections;
     BensonAtomConnections *Connections;
     BensonSecondThermoTable *TableValues;
     };
#define BensonSecondOrderSize sizeof(BensonSecondOrder)
#define AllocateBensonSecondOrder (BensonSecondOrder *) Malloc(BensonSecondOrderSize)
#define AllocArrayBensonSecondOrder(n) (BensonSecondOrder *) Calloc(n,BensonSecondOrderSize)
#define BensonSecondOrderPntrSize sizeof(BensonSecondOrder **)
#define AllocPntrArrayBensonSecondOrder(n) (BensonSecondOrder **) Calloc(n,BensonSecondOrderPntrSize)
#define SingCopyBensonSecondOrder(out,in) memcpy(out,in,BensonSecondOrderSize)
extern BensonSecondOrder *CreateBensonSecondOrder(BensonSecondOrder *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  CenterAtom,
                                           INT  NumberOfConnections,
                                           BensonAtomConnections *Connections,
                                           BensonSecondThermoTable *TableValues);

extern CHAR *GetNameBensonSecondOrder(BensonSecondOrder *str);
extern INT  GetIDBensonSecondOrder(BensonSecondOrder *str);
extern void PrintBensonSecondOrder(BensonSecondOrder *eleptr);
extern void FreeBensonSecondOrder(BensonSecondOrder *eleptr);
extern void *AllocBensonSecondOrder();
extern void WriteBinBensonSecondOrder(BensonSecondOrder *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonSecondOrder(BensonSecondOrder *eleptr, DbaseLinkedList *file);
extern void xdr_BensonSecondOrder(XDR *stream, char **eleptr);
extern void CopyFullBensonSecondOrder(BensonSecondOrder *newstruct, BensonSecondOrder *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:103:BensonSecondOrderTable

      NumberOfTableValues --(INT) The number of Table Values
                   Values --(BensonSecondOrder) The table values
     NumberOfTemperatures --(INT) The number temperatures for heat capacities
             Temperatures --(FLOAT) The set of Temperatures
                Reference --(STRING) Reference
*/
typedef struct bensonsecondordertable BensonSecondOrderTable;
struct bensonsecondordertable {
     INT ID;
     CHAR *Name;
     INT  NumberOfTableValues;
     BensonSecondOrder *Values;
     INT  NumberOfTemperatures;
     FLOAT *Temperatures;
     STRING *Reference;
     };
#define BensonSecondOrderTableSize sizeof(BensonSecondOrderTable)
#define AllocateBensonSecondOrderTable (BensonSecondOrderTable *) Malloc(BensonSecondOrderTableSize)
#define AllocArrayBensonSecondOrderTable(n) (BensonSecondOrderTable *) Calloc(n,BensonSecondOrderTableSize)
#define BensonSecondOrderTablePntrSize sizeof(BensonSecondOrderTable **)
#define AllocPntrArrayBensonSecondOrderTable(n) (BensonSecondOrderTable **) Calloc(n,BensonSecondOrderTablePntrSize)
#define SingCopyBensonSecondOrderTable(out,in) memcpy(out,in,BensonSecondOrderTableSize)
extern BensonSecondOrderTable *CreateBensonSecondOrderTable(BensonSecondOrderTable *newstruct,
                                                     INT id,
                                                     CHAR *name,
                                                     INT  NumberOfTableValues,
                                                     BensonSecondOrder *Values,
                                                     INT  NumberOfTemperatures,
                                                     FLOAT *Temperatures,
                                                     STRING *Reference);

extern CHAR *GetNameBensonSecondOrderTable(BensonSecondOrderTable *str);
extern INT  GetIDBensonSecondOrderTable(BensonSecondOrderTable *str);
extern void PrintBensonSecondOrderTable(BensonSecondOrderTable *eleptr);
extern void FreeBensonSecondOrderTable(BensonSecondOrderTable *eleptr);
extern void *AllocBensonSecondOrderTable();
extern void WriteBinBensonSecondOrderTable(BensonSecondOrderTable *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonSecondOrderTable(BensonSecondOrderTable *eleptr, DbaseLinkedList *file);
extern void xdr_BensonSecondOrderTable(XDR *stream, char **eleptr);
extern void CopyFullBensonSecondOrderTable(BensonSecondOrderTable *newstruct, BensonSecondOrderTable *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:104:SetOfBenson2ndOrderTables

           NumberOfTables --(INT) The number of tables
                   Tables --(BensonSecondOrderTable) The set of tables
*/
typedef struct setofbenson2ndordertables SetOfBenson2ndOrderTables;
struct setofbenson2ndordertables {
     INT ID;
     CHAR *Name;
     INT  NumberOfTables;
     BensonSecondOrderTable *Tables;
     };
#define SetOfBenson2ndOrderTablesSize sizeof(SetOfBenson2ndOrderTables)
#define AllocateSetOfBenson2ndOrderTables (SetOfBenson2ndOrderTables *) Malloc(SetOfBenson2ndOrderTablesSize)
#define AllocArraySetOfBenson2ndOrderTables(n) (SetOfBenson2ndOrderTables *) Calloc(n,SetOfBenson2ndOrderTablesSize)
#define SetOfBenson2ndOrderTablesPntrSize sizeof(SetOfBenson2ndOrderTables **)
#define AllocPntrArraySetOfBenson2ndOrderTables(n) (SetOfBenson2ndOrderTables **) Calloc(n,SetOfBenson2ndOrderTablesPntrSize)
#define SingCopySetOfBenson2ndOrderTables(out,in) memcpy(out,in,SetOfBenson2ndOrderTablesSize)
extern SetOfBenson2ndOrderTables *CreateSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *newstruct,
INT id,
CHAR *name,
INT  NumberOfTables,
BensonSecondOrderTable *Tables);

extern CHAR *GetNameSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *str);
extern INT  GetIDSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *str);
extern void PrintSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr);
extern void FreeSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr);
extern void *AllocSetOfBenson2ndOrderTables();
extern void WriteBinSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfBenson2ndOrderTables(XDR *stream, char **eleptr);
extern void CopyFullSetOfBenson2ndOrderTables(SetOfBenson2ndOrderTables *newstruct, SetOfBenson2ndOrderTables *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:105:BensonTranslationPair

                  Valence --(INT) The Valence Value
                 AtomName --(STRING) The Name
*/
typedef struct bensontranslationelement BensonTranslationPair;
struct bensontranslationelement {
     INT ID;
     CHAR *Name;
     INT  Valence;
     STRING *AtomName;
     };
#define BensonTranslationPairSize sizeof(BensonTranslationPair)
#define AllocateBensonTranslationPair (BensonTranslationPair *) Malloc(BensonTranslationPairSize)
#define AllocArrayBensonTranslationPair(n) (BensonTranslationPair *) Calloc(n,BensonTranslationPairSize)
#define BensonTranslationPairPntrSize sizeof(BensonTranslationPair **)
#define AllocPntrArrayBensonTranslationPair(n) (BensonTranslationPair **) Calloc(n,BensonTranslationPairPntrSize)
#define SingCopyBensonTranslationPair(out,in) memcpy(out,in,BensonTranslationPairSize)
extern BensonTranslationPair *CreateBensonTranslationPair(BensonTranslationPair *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Valence,
                                                   STRING *AtomName);

extern CHAR *GetNameBensonTranslationPair(BensonTranslationPair *str);
extern INT  GetIDBensonTranslationPair(BensonTranslationPair *str);
extern void PrintBensonTranslationPair(BensonTranslationPair *eleptr);
extern void FreeBensonTranslationPair(BensonTranslationPair *eleptr);
extern void *AllocBensonTranslationPair();
extern void WriteBinBensonTranslationPair(BensonTranslationPair *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonTranslationPair(BensonTranslationPair *eleptr, DbaseLinkedList *file);
extern void xdr_BensonTranslationPair(XDR *stream, char **eleptr);
extern void CopyFullBensonTranslationPair(BensonTranslationPair *newstruct, BensonTranslationPair *oldstruct);
/*------------------------------------------*/
/*   Benson Thermodynamic Constants   */
/* Structure:106:SetOfBensonAtomTranslationPairs

            NumberOfPairs --(INT) The number of pairs
                    Pairs --(BensonTranslationPair) The set of Translation Pairs
*/
typedef struct setofbensontranslationelpairs SetOfBensonAtomTranslationPairs;
struct setofbensontranslationelpairs {
     INT ID;
     CHAR *Name;
     INT  NumberOfPairs;
     BensonTranslationPair *Pairs;
     };
#define SetOfBensonAtomTranslationPairsSize sizeof(SetOfBensonAtomTranslationPairs)
#define AllocateSetOfBensonAtomTranslationPairs (SetOfBensonAtomTranslationPairs *) Malloc(SetOfBensonAtomTranslationPairsSize)
#define AllocArraySetOfBensonAtomTranslationPairs(n) (SetOfBensonAtomTranslationPairs *) Calloc(n,SetOfBensonAtomTranslationPairsSize)
#define SetOfBensonAtomTranslationPairsPntrSize sizeof(SetOfBensonAtomTranslationPairs **)
#define AllocPntrArraySetOfBensonAtomTranslationPairs(n) (SetOfBensonAtomTranslationPairs **) Calloc(n,SetOfBensonAtomTranslationPairsPntrSize)
#define SingCopySetOfBensonAtomTranslationPairs(out,in) memcpy(out,in,SetOfBensonAtomTranslationPairsSize)
extern SetOfBensonAtomTranslationPairs *CreateSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *newstruct,
INT id,
CHAR *name,
INT  NumberOfPairs,
BensonTranslationPair *Pairs);

extern CHAR *GetNameSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *str);
extern INT  GetIDSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *str);
extern void PrintSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr);
extern void FreeSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr);
extern void *AllocSetOfBensonAtomTranslationPairs();
extern void WriteBinSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfBensonAtomTranslationPairs(XDR *stream, char **eleptr);
extern void CopyFullSetOfBensonAtomTranslationPairs(SetOfBensonAtomTranslationPairs *newstruct, SetOfBensonAtomTranslationPairs *oldstruct);
