/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:100:BensonCalcConnections

        NumberOfNeighbors --(INT) The number of Neighbors
                 Valences --(INT) The set of Valences of Neighbors
     NumberOfUniqueConnections --(INT) The Number of Unique Connections
              Connections --(BensonAtomConnections) The Set of Connections and Multiplicities
*/
typedef struct bensoncalcconnections BensonCalcConnections;
struct bensoncalcconnections {
     INT ID;
     CHAR *Name;
     INT  NumberOfNeighbors;
     INT *Valences;
     INT  NumberOfUniqueConnections;
     BensonAtomConnections *Connections;
     };
#define BensonCalcConnectionsSize sizeof(BensonCalcConnections)
#define AllocateBensonCalcConnections (BensonCalcConnections *) Malloc(BensonCalcConnectionsSize)
#define AllocArrayBensonCalcConnections(n) (BensonCalcConnections *) Calloc(n,BensonCalcConnectionsSize)
#define BensonCalcConnectionsPntrSize sizeof(BensonCalcConnections **)
#define AllocPntrArrayBensonCalcConnections(n) (BensonCalcConnections **) Calloc(n,BensonCalcConnectionsPntrSize)
#define SingCopyBensonCalcConnections(out,in) memcpy(out,in,BensonCalcConnectionsSize)
extern BensonCalcConnections *CreateBensonCalcConnections(BensonCalcConnections *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfNeighbors,
                                                   INT *Valences,
                                                   INT  NumberOfUniqueConnections,
                                                   BensonAtomConnections *Connections);

extern CHAR *GetNameBensonCalcConnections(BensonCalcConnections *str);
extern INT  GetIDBensonCalcConnections(BensonCalcConnections *str);
extern void PrintBensonCalcConnections(BensonCalcConnections *eleptr);
extern void FreeBensonCalcConnections(BensonCalcConnections *eleptr);
extern void *AllocBensonCalcConnections();
extern void WriteBinBensonCalcConnections(BensonCalcConnections *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonCalcConnections(BensonCalcConnections *eleptr, DbaseLinkedList *file);
extern void xdr_BensonCalcConnections(XDR *stream, char **eleptr);
extern void CopyFullBensonCalcConnections(BensonCalcConnections *newstruct, BensonCalcConnections *oldstruct);
/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:101:SetOfBensonCalcConnections

            NumberOfAtoms --(INT) The number of atoms
              Connections --(BensonCalcConnections) The set of Connections for each Atom
*/
typedef struct setofbensoncalcconnections SetOfBensonCalcConnections;
struct setofbensoncalcconnections {
     INT ID;
     CHAR *Name;
     INT  NumberOfAtoms;
     BensonCalcConnections *Connections;
     };
#define SetOfBensonCalcConnectionsSize sizeof(SetOfBensonCalcConnections)
#define AllocateSetOfBensonCalcConnections (SetOfBensonCalcConnections *) Malloc(SetOfBensonCalcConnectionsSize)
#define AllocArraySetOfBensonCalcConnections(n) (SetOfBensonCalcConnections *) Calloc(n,SetOfBensonCalcConnectionsSize)
#define SetOfBensonCalcConnectionsPntrSize sizeof(SetOfBensonCalcConnections **)
#define AllocPntrArraySetOfBensonCalcConnections(n) (SetOfBensonCalcConnections **) Calloc(n,SetOfBensonCalcConnectionsPntrSize)
#define SingCopySetOfBensonCalcConnections(out,in) memcpy(out,in,SetOfBensonCalcConnectionsSize)
extern SetOfBensonCalcConnections *CreateSetOfBensonCalcConnections(SetOfBensonCalcConnections *newstruct,
INT id,
CHAR *name,
INT  NumberOfAtoms,
BensonCalcConnections *Connections);

extern CHAR *GetNameSetOfBensonCalcConnections(SetOfBensonCalcConnections *str);
extern INT  GetIDSetOfBensonCalcConnections(SetOfBensonCalcConnections *str);
extern void PrintSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr);
extern void FreeSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr);
extern void *AllocSetOfBensonCalcConnections();
extern void WriteBinSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfBensonCalcConnections(XDR *stream, char **eleptr);
extern void CopyFullSetOfBensonCalcConnections(SetOfBensonCalcConnections *newstruct, SetOfBensonCalcConnections *oldstruct);
/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:100:BensonConnectionTree

               Connection --(BensonAtomConnections) The Connection Valence and Multiplicity (Zero if the first one after Central atom)
             ThermoValues --(BensonSecondThermoTable) If Finished, the thermodynamic values
     NumberOfConnectionCases --(INT) The number of Further Connection Cases
                    Cases --(BensonConnectionTree) The further Connection Cases
*/
typedef struct bensonconnectiontree BensonConnectionTree;
struct bensonconnectiontree {
     INT ID;
     CHAR *Name;
     BensonAtomConnections *Connection;
     BensonSecondThermoTable *ThermoValues;
     INT  NumberOfConnectionCases;
     BensonConnectionTree *Cases;
     };
#define BensonConnectionTreeSize sizeof(BensonConnectionTree)
#define AllocateBensonConnectionTree (BensonConnectionTree *) Malloc(BensonConnectionTreeSize)
#define AllocArrayBensonConnectionTree(n) (BensonConnectionTree *) Calloc(n,BensonConnectionTreeSize)
#define BensonConnectionTreePntrSize sizeof(BensonConnectionTree **)
#define AllocPntrArrayBensonConnectionTree(n) (BensonConnectionTree **) Calloc(n,BensonConnectionTreePntrSize)
#define SingCopyBensonConnectionTree(out,in) memcpy(out,in,BensonConnectionTreeSize)
extern BensonConnectionTree *CreateBensonConnectionTree(BensonConnectionTree *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 BensonAtomConnections *Connection,
                                                 BensonSecondThermoTable *ThermoValues,
                                                 INT  NumberOfConnectionCases,
                                                 BensonConnectionTree *Cases);

extern CHAR *GetNameBensonConnectionTree(BensonConnectionTree *str);
extern INT  GetIDBensonConnectionTree(BensonConnectionTree *str);
extern void PrintBensonConnectionTree(BensonConnectionTree *eleptr);
extern void FreeBensonConnectionTree(BensonConnectionTree *eleptr);
extern void *AllocBensonConnectionTree();
extern void WriteBinBensonConnectionTree(BensonConnectionTree *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonConnectionTree(BensonConnectionTree *eleptr, DbaseLinkedList *file);
extern void xdr_BensonConnectionTree(XDR *stream, char **eleptr);
extern void CopyFullBensonConnectionTree(BensonConnectionTree *newstruct, BensonConnectionTree *oldstruct);
/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:100:CentralAtomBranch

       CentralAtomValence --(INT) Central Atom Valence
                     Tree --(BensonConnectionTree) The Connection Tree
*/
typedef struct bensoncentralatombranch CentralAtomBranch;
struct bensoncentralatombranch {
     INT ID;
     CHAR *Name;
     INT  CentralAtomValence;
     BensonConnectionTree *Tree;
     };
#define CentralAtomBranchSize sizeof(CentralAtomBranch)
#define AllocateCentralAtomBranch (CentralAtomBranch *) Malloc(CentralAtomBranchSize)
#define AllocArrayCentralAtomBranch(n) (CentralAtomBranch *) Calloc(n,CentralAtomBranchSize)
#define CentralAtomBranchPntrSize sizeof(CentralAtomBranch **)
#define AllocPntrArrayCentralAtomBranch(n) (CentralAtomBranch **) Calloc(n,CentralAtomBranchPntrSize)
#define SingCopyCentralAtomBranch(out,in) memcpy(out,in,CentralAtomBranchSize)
extern CentralAtomBranch *CreateCentralAtomBranch(CentralAtomBranch *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  CentralAtomValence,
                                           BensonConnectionTree *Tree);

extern CHAR *GetNameCentralAtomBranch(CentralAtomBranch *str);
extern INT  GetIDCentralAtomBranch(CentralAtomBranch *str);
extern void PrintCentralAtomBranch(CentralAtomBranch *eleptr);
extern void FreeCentralAtomBranch(CentralAtomBranch *eleptr);
extern void *AllocCentralAtomBranch();
extern void WriteBinCentralAtomBranch(CentralAtomBranch *eleptr, DbaseLinkedList *file);
extern INT ReadBinCentralAtomBranch(CentralAtomBranch *eleptr, DbaseLinkedList *file);
extern void xdr_CentralAtomBranch(XDR *stream, char **eleptr);
extern void CopyFullCentralAtomBranch(CentralAtomBranch *newstruct, CentralAtomBranch *oldstruct);
/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:100:SecondOrderBensonTree

     NumberOfCentralAtomTypes --(INT) Number of Central Atom Types
          CentralAtomTree --(CentralAtomBranch) The Central Atom Tree
*/
typedef struct secondorderbensontree SecondOrderBensonTree;
struct secondorderbensontree {
     INT ID;
     CHAR *Name;
     INT  NumberOfCentralAtomTypes;
     CentralAtomBranch *CentralAtomTree;
     };
#define SecondOrderBensonTreeSize sizeof(SecondOrderBensonTree)
#define AllocateSecondOrderBensonTree (SecondOrderBensonTree *) Malloc(SecondOrderBensonTreeSize)
#define AllocArraySecondOrderBensonTree(n) (SecondOrderBensonTree *) Calloc(n,SecondOrderBensonTreeSize)
#define SecondOrderBensonTreePntrSize sizeof(SecondOrderBensonTree **)
#define AllocPntrArraySecondOrderBensonTree(n) (SecondOrderBensonTree **) Calloc(n,SecondOrderBensonTreePntrSize)
#define SingCopySecondOrderBensonTree(out,in) memcpy(out,in,SecondOrderBensonTreeSize)
extern SecondOrderBensonTree *CreateSecondOrderBensonTree(SecondOrderBensonTree *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfCentralAtomTypes,
                                                   CentralAtomBranch *CentralAtomTree);

extern CHAR *GetNameSecondOrderBensonTree(SecondOrderBensonTree *str);
extern INT  GetIDSecondOrderBensonTree(SecondOrderBensonTree *str);
extern void PrintSecondOrderBensonTree(SecondOrderBensonTree *eleptr);
extern void FreeSecondOrderBensonTree(SecondOrderBensonTree *eleptr);
extern void *AllocSecondOrderBensonTree();
extern void WriteBinSecondOrderBensonTree(SecondOrderBensonTree *eleptr, DbaseLinkedList *file);
extern INT ReadBinSecondOrderBensonTree(SecondOrderBensonTree *eleptr, DbaseLinkedList *file);
extern void xdr_SecondOrderBensonTree(XDR *stream, char **eleptr);
extern void CopyFullSecondOrderBensonTree(SecondOrderBensonTree *newstruct, SecondOrderBensonTree *oldstruct);
/*------------------------------------------*/
/*   Benson Calculations   */
/* Structure:100:BensonCalculation

          SecondOrderTree --(SecondOrderBensonTree) The Second Order Central Atom Tree
     NumberOfTemperatures --(INT) The number of temperatures for the Heat Capactities
*/
typedef struct bensoncalculation BensonCalculation;
struct bensoncalculation {
     INT ID;
     CHAR *Name;
     SecondOrderBensonTree *SecondOrderTree;
     INT  NumberOfTemperatures;
     };
#define BensonCalculationSize sizeof(BensonCalculation)
#define AllocateBensonCalculation (BensonCalculation *) Malloc(BensonCalculationSize)
#define AllocArrayBensonCalculation(n) (BensonCalculation *) Calloc(n,BensonCalculationSize)
#define BensonCalculationPntrSize sizeof(BensonCalculation **)
#define AllocPntrArrayBensonCalculation(n) (BensonCalculation **) Calloc(n,BensonCalculationPntrSize)
#define SingCopyBensonCalculation(out,in) memcpy(out,in,BensonCalculationSize)
extern BensonCalculation *CreateBensonCalculation(BensonCalculation *newstruct,
                                           INT id,
                                           CHAR *name,
                                           SecondOrderBensonTree *SecondOrderTree,
                                           INT  NumberOfTemperatures);

extern CHAR *GetNameBensonCalculation(BensonCalculation *str);
extern INT  GetIDBensonCalculation(BensonCalculation *str);
extern void PrintBensonCalculation(BensonCalculation *eleptr);
extern void FreeBensonCalculation(BensonCalculation *eleptr);
extern void *AllocBensonCalculation();
extern void WriteBinBensonCalculation(BensonCalculation *eleptr, DbaseLinkedList *file);
extern INT ReadBinBensonCalculation(BensonCalculation *eleptr, DbaseLinkedList *file);
extern void xdr_BensonCalculation(XDR *stream, char **eleptr);
extern void CopyFullBensonCalculation(BensonCalculation *newstruct, BensonCalculation *oldstruct);
