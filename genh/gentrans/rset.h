/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:100:PerformedRxnInfoConstants

           SymmetryFactor --(INT) The Symmetry Factor
                   Weight --(FLOAT) The Weighting (corresponds to the reaction constant
                Aconstant --(FLOAT) The Arrhenius Constant
                   Energy --(FLOAT) The Activation Energy
                  TempExp --(FLOAT) The Temperature Exponent
*/
typedef struct performedrxninfoconstants PerformedRxnInfoConstants;
struct performedrxninfoconstants {
     INT ID;
     CHAR *Name;
     INT  SymmetryFactor;
     FLOAT  Weight;
     FLOAT  Aconstant;
     FLOAT  Energy;
     FLOAT  TempExp;
     };
#define PerformedRxnInfoConstantsSize sizeof(PerformedRxnInfoConstants)
#define AllocatePerformedRxnInfoConstants (PerformedRxnInfoConstants *) Malloc(PerformedRxnInfoConstantsSize)
#define AllocArrayPerformedRxnInfoConstants(n) (PerformedRxnInfoConstants *) Calloc(n,PerformedRxnInfoConstantsSize)
#define PerformedRxnInfoConstantsPntrSize sizeof(PerformedRxnInfoConstants **)
#define AllocPntrArrayPerformedRxnInfoConstants(n) (PerformedRxnInfoConstants **) Calloc(n,PerformedRxnInfoConstantsPntrSize)
#define SingCopyPerformedRxnInfoConstants(out,in) memcpy(out,in,PerformedRxnInfoConstantsSize)
extern PerformedRxnInfoConstants *CreatePerformedRxnInfoConstants(PerformedRxnInfoConstants *newstruct,
INT id,
CHAR *name,
INT  SymmetryFactor,
FLOAT  Weight,
FLOAT  Aconstant,
FLOAT  Energy,
FLOAT  TempExp);

extern CHAR *GetNamePerformedRxnInfoConstants(PerformedRxnInfoConstants *str);
extern INT  GetIDPerformedRxnInfoConstants(PerformedRxnInfoConstants *str);
extern void PrintPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr);
extern void FreePerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr);
extern void *AllocPerformedRxnInfoConstants();
extern void WriteBinPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr, DbaseLinkedList *file);
extern void xdr_PerformedRxnInfoConstants(XDR *stream, char **eleptr);
extern void CopyFullPerformedRxnInfoConstants(PerformedRxnInfoConstants *newstruct, PerformedRxnInfoConstants *oldstruct);
/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:101:PerformedRxnInfo

                  Forward --(PerformedRxnInfoConstants) The forward set of constants
                  Reverse --(PerformedRxnInfoConstants) The reverse set of constants
*/
typedef struct performedrxninfo PerformedRxnInfo;
struct performedrxninfo {
     INT ID;
     CHAR *Name;
     PerformedRxnInfoConstants *Forward;
     PerformedRxnInfoConstants *Reverse;
     };
#define PerformedRxnInfoSize sizeof(PerformedRxnInfo)
#define AllocatePerformedRxnInfo (PerformedRxnInfo *) Malloc(PerformedRxnInfoSize)
#define AllocArrayPerformedRxnInfo(n) (PerformedRxnInfo *) Calloc(n,PerformedRxnInfoSize)
#define PerformedRxnInfoPntrSize sizeof(PerformedRxnInfo **)
#define AllocPntrArrayPerformedRxnInfo(n) (PerformedRxnInfo **) Calloc(n,PerformedRxnInfoPntrSize)
#define SingCopyPerformedRxnInfo(out,in) memcpy(out,in,PerformedRxnInfoSize)
extern PerformedRxnInfo *CreatePerformedRxnInfo(PerformedRxnInfo *newstruct,
                                         INT id,
                                         CHAR *name,
                                         PerformedRxnInfoConstants *Forward,
                                         PerformedRxnInfoConstants *Reverse);

extern CHAR *GetNamePerformedRxnInfo(PerformedRxnInfo *str);
extern INT  GetIDPerformedRxnInfo(PerformedRxnInfo *str);
extern void PrintPerformedRxnInfo(PerformedRxnInfo *eleptr);
extern void FreePerformedRxnInfo(PerformedRxnInfo *eleptr);
extern void *AllocPerformedRxnInfo();
extern void WriteBinPerformedRxnInfo(PerformedRxnInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinPerformedRxnInfo(PerformedRxnInfo *eleptr, DbaseLinkedList *file);
extern void xdr_PerformedRxnInfo(XDR *stream, char **eleptr);
extern void CopyFullPerformedRxnInfo(PerformedRxnInfo *newstruct, PerformedRxnInfo *oldstruct);
/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:101:SetOfPerformedRxnInfo

        NumberOfReactions --(INT) The number of reactions
                      Set --(PerformedRxnInfo) The Set of Performed Reaction Information
*/
typedef struct setofperformedrxninfo SetOfPerformedRxnInfo;
struct setofperformedrxninfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     PerformedRxnInfo *Set;
     };
#define SetOfPerformedRxnInfoSize sizeof(SetOfPerformedRxnInfo)
#define AllocateSetOfPerformedRxnInfo (SetOfPerformedRxnInfo *) Malloc(SetOfPerformedRxnInfoSize)
#define AllocArraySetOfPerformedRxnInfo(n) (SetOfPerformedRxnInfo *) Calloc(n,SetOfPerformedRxnInfoSize)
#define SetOfPerformedRxnInfoPntrSize sizeof(SetOfPerformedRxnInfo **)
#define AllocPntrArraySetOfPerformedRxnInfo(n) (SetOfPerformedRxnInfo **) Calloc(n,SetOfPerformedRxnInfoPntrSize)
#define SingCopySetOfPerformedRxnInfo(out,in) memcpy(out,in,SetOfPerformedRxnInfoSize)
extern SetOfPerformedRxnInfo *CreateSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfReactions,
                                                   PerformedRxnInfo *Set);

extern CHAR *GetNameSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *str);
extern INT  GetIDSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *str);
extern void PrintSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr);
extern void FreeSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr);
extern void *AllocSetOfPerformedRxnInfo();
extern void WriteBinSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfPerformedRxnInfo(XDR *stream, char **eleptr);
extern void CopyFullSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *newstruct, SetOfPerformedRxnInfo *oldstruct);
/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:101:PerformedRxn

        NumberOfReactants --(INT) The number of reactants
         NumberOfProducts --(INT) The number of products
              ReactantIDs --(INT) The set of Reactant ID's
               ProductIDs --(INT) The set of Product ID's
                     Info --(PerformedRxnInfo) The Information about the reaction
*/
typedef struct performedrxn PerformedRxn;
struct performedrxn {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactants;
     INT  NumberOfProducts;
     INT *ReactantIDs;
     INT *ProductIDs;
     PerformedRxnInfo *Info;
     };
#define PerformedRxnSize sizeof(PerformedRxn)
#define AllocatePerformedRxn (PerformedRxn *) Malloc(PerformedRxnSize)
#define AllocArrayPerformedRxn(n) (PerformedRxn *) Calloc(n,PerformedRxnSize)
#define PerformedRxnPntrSize sizeof(PerformedRxn **)
#define AllocPntrArrayPerformedRxn(n) (PerformedRxn **) Calloc(n,PerformedRxnPntrSize)
#define SingCopyPerformedRxn(out,in) memcpy(out,in,PerformedRxnSize)
extern PerformedRxn *CreatePerformedRxn(PerformedRxn *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfReactants,
                                 INT  NumberOfProducts,
                                 INT *ReactantIDs,
                                 INT *ProductIDs,
                                 PerformedRxnInfo *Info);

extern CHAR *GetNamePerformedRxn(PerformedRxn *str);
extern INT  GetIDPerformedRxn(PerformedRxn *str);
extern void PrintPerformedRxn(PerformedRxn *eleptr);
extern void FreePerformedRxn(PerformedRxn *eleptr);
extern void *AllocPerformedRxn();
extern void WriteBinPerformedRxn(PerformedRxn *eleptr, DbaseLinkedList *file);
extern INT ReadBinPerformedRxn(PerformedRxn *eleptr, DbaseLinkedList *file);
extern void xdr_PerformedRxn(XDR *stream, char **eleptr);
extern void CopyFullPerformedRxn(PerformedRxn *newstruct, PerformedRxn *oldstruct);
/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:102:SetOfPerformedRxns

        NumberOfReactions --(INT) The Number Of Individual Reactions
                Reactions --(PerformedRxn) The Set of Individual Reactions
*/
typedef struct setofperformedrxns SetOfPerformedRxns;
struct setofperformedrxns {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     PerformedRxn *Reactions;
     };
#define SetOfPerformedRxnsSize sizeof(SetOfPerformedRxns)
#define AllocateSetOfPerformedRxns (SetOfPerformedRxns *) Malloc(SetOfPerformedRxnsSize)
#define AllocArraySetOfPerformedRxns(n) (SetOfPerformedRxns *) Calloc(n,SetOfPerformedRxnsSize)
#define SetOfPerformedRxnsPntrSize sizeof(SetOfPerformedRxns **)
#define AllocPntrArraySetOfPerformedRxns(n) (SetOfPerformedRxns **) Calloc(n,SetOfPerformedRxnsPntrSize)
#define SingCopySetOfPerformedRxns(out,in) memcpy(out,in,SetOfPerformedRxnsSize)
extern SetOfPerformedRxns *CreateSetOfPerformedRxns(SetOfPerformedRxns *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfReactions,
                                             PerformedRxn *Reactions);

extern CHAR *GetNameSetOfPerformedRxns(SetOfPerformedRxns *str);
extern INT  GetIDSetOfPerformedRxns(SetOfPerformedRxns *str);
extern void PrintSetOfPerformedRxns(SetOfPerformedRxns *eleptr);
extern void FreeSetOfPerformedRxns(SetOfPerformedRxns *eleptr);
extern void *AllocSetOfPerformedRxns();
extern void WriteBinSetOfPerformedRxns(SetOfPerformedRxns *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfPerformedRxns(SetOfPerformedRxns *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfPerformedRxns(XDR *stream, char **eleptr);
extern void CopyFullSetOfPerformedRxns(SetOfPerformedRxns *newstruct, SetOfPerformedRxns *oldstruct);
/*------------------------------------------*/
/*   Reaction Tree Structures   */
/* Structure:103:PerformedRxnMaster

                Direction --(INT) The direction of the reaction (REACTANT or PRODUCT)
                Molecules --(SetOfGraphs) The Set of Molecules Created by set of reactions
                Reactions --(TransformSet) The Set of Reactions as Graphs
         MoleculeAtomSets --(DataSubSetVector) The Set of Atom Sets
                Performed --(SetOfPerformedRxns) The set of reactions
              Adjustments --(SetOfPerformedRxnInfo) The Set of Adjustments to reaction factors
*/
typedef struct performedrxnmaster PerformedRxnMaster;
struct performedrxnmaster {
     INT ID;
     CHAR *Name;
     INT  Direction;
     SetOfGraphs *Molecules;
     TransformSet *Reactions;
     DataSubSetVector *MoleculeAtomSets;
     SetOfPerformedRxns *Performed;
     SetOfPerformedRxnInfo *Adjustments;
     };
#define PerformedRxnMasterSize sizeof(PerformedRxnMaster)
#define AllocatePerformedRxnMaster (PerformedRxnMaster *) Malloc(PerformedRxnMasterSize)
#define AllocArrayPerformedRxnMaster(n) (PerformedRxnMaster *) Calloc(n,PerformedRxnMasterSize)
#define PerformedRxnMasterPntrSize sizeof(PerformedRxnMaster **)
#define AllocPntrArrayPerformedRxnMaster(n) (PerformedRxnMaster **) Calloc(n,PerformedRxnMasterPntrSize)
#define SingCopyPerformedRxnMaster(out,in) memcpy(out,in,PerformedRxnMasterSize)
extern PerformedRxnMaster *CreatePerformedRxnMaster(PerformedRxnMaster *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  Direction,
                                             SetOfGraphs *Molecules,
                                             TransformSet *Reactions,
                                             DataSubSetVector *MoleculeAtomSets,
                                             SetOfPerformedRxns *Performed,
                                             SetOfPerformedRxnInfo *Adjustments);

extern CHAR *GetNamePerformedRxnMaster(PerformedRxnMaster *str);
extern INT  GetIDPerformedRxnMaster(PerformedRxnMaster *str);
extern void PrintPerformedRxnMaster(PerformedRxnMaster *eleptr);
extern void FreePerformedRxnMaster(PerformedRxnMaster *eleptr);
extern void *AllocPerformedRxnMaster();
extern void WriteBinPerformedRxnMaster(PerformedRxnMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinPerformedRxnMaster(PerformedRxnMaster *eleptr, DbaseLinkedList *file);
extern void xdr_PerformedRxnMaster(XDR *stream, char **eleptr);
extern void CopyFullPerformedRxnMaster(PerformedRxnMaster *newstruct, PerformedRxnMaster *oldstruct);
