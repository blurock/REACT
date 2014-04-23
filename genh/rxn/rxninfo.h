/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:60:RxnAtom

           MoleculeNumber --(INT) The Molecule
               AtomNumber --(INT) The Atom in Molecule
*/
typedef struct rxnatom RxnAtom;
struct rxnatom {
     INT ID;
     CHAR *Name;
     INT  MoleculeNumber;
     INT  AtomNumber;
     };
#define RxnAtomSize sizeof(RxnAtom)
#define AllocateRxnAtom (RxnAtom *) Malloc(RxnAtomSize)
#define AllocArrayRxnAtom(n) (RxnAtom *) Calloc(n,RxnAtomSize)
#define RxnAtomPntrSize sizeof(RxnAtom **)
#define AllocPntrArrayRxnAtom(n) (RxnAtom **) Calloc(n,RxnAtomPntrSize)
#define SingCopyRxnAtom(out,in) memcpy(out,in,RxnAtomSize)
extern RxnAtom *CreateRxnAtom(RxnAtom *newstruct,
                       INT id,
                       CHAR *name,
                       INT  MoleculeNumber,
                       INT  AtomNumber);

extern CHAR *GetNameRxnAtom(RxnAtom *str);
extern INT  GetIDRxnAtom(RxnAtom *str);
extern void PrintRxnAtom(RxnAtom *eleptr);
extern void FreeRxnAtom(RxnAtom *eleptr);
extern void *AllocRxnAtom();
extern void WriteBinRxnAtom(RxnAtom *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnAtom(RxnAtom *eleptr, DbaseLinkedList *file);
extern void xdr_RxnAtom(XDR *stream, char **eleptr);
extern void CopyFullRxnAtom(RxnAtom *newstruct, RxnAtom *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:61:RxnAtomCorrespondence

                  Product --(RxnAtom) The Product Atom
                 Reactant --(RxnAtom) The Reactant Atom
         ReactantPosition --(INT) The Molecule Position in the set of Reactants
          ProductPosition --(INT) The Molecule Position in the set of Products
*/
typedef struct rxnatomcorr RxnAtomCorrespondence;
struct rxnatomcorr {
     INT ID;
     CHAR *Name;
     RxnAtom *Product;
     RxnAtom *Reactant;
     INT  ReactantPosition;
     INT  ProductPosition;
     };
#define RxnAtomCorrespondenceSize sizeof(RxnAtomCorrespondence)
#define AllocateRxnAtomCorrespondence (RxnAtomCorrespondence *) Malloc(RxnAtomCorrespondenceSize)
#define AllocArrayRxnAtomCorrespondence(n) (RxnAtomCorrespondence *) Calloc(n,RxnAtomCorrespondenceSize)
#define RxnAtomCorrespondencePntrSize sizeof(RxnAtomCorrespondence **)
#define AllocPntrArrayRxnAtomCorrespondence(n) (RxnAtomCorrespondence **) Calloc(n,RxnAtomCorrespondencePntrSize)
#define SingCopyRxnAtomCorrespondence(out,in) memcpy(out,in,RxnAtomCorrespondenceSize)
extern RxnAtomCorrespondence *CreateRxnAtomCorrespondence(RxnAtomCorrespondence *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   RxnAtom *Product,
                                                   RxnAtom *Reactant,
                                                   INT  ReactantPosition,
                                                   INT  ProductPosition);

extern CHAR *GetNameRxnAtomCorrespondence(RxnAtomCorrespondence *str);
extern INT  GetIDRxnAtomCorrespondence(RxnAtomCorrespondence *str);
extern void PrintRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr);
extern void FreeRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr);
extern void *AllocRxnAtomCorrespondence();
extern void WriteBinRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr, DbaseLinkedList *file);
extern void xdr_RxnAtomCorrespondence(XDR *stream, char **eleptr);
extern void CopyFullRxnAtomCorrespondence(RxnAtomCorrespondence *newstruct, RxnAtomCorrespondence *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:62:RxnUnMatchedSet

     NumberUnMatchedAtoms --(INT) The Number of Unmatched Reactants
           UnMatchedAtoms --(RxnAtom) The Unmatched Reactant Atoms
*/
typedef struct rxnunmatchedset RxnUnMatchedSet;
struct rxnunmatchedset {
     INT ID;
     CHAR *Name;
     INT  NumberUnMatchedAtoms;
     RxnAtom *UnMatchedAtoms;
     };
#define RxnUnMatchedSetSize sizeof(RxnUnMatchedSet)
#define AllocateRxnUnMatchedSet (RxnUnMatchedSet *) Malloc(RxnUnMatchedSetSize)
#define AllocArrayRxnUnMatchedSet(n) (RxnUnMatchedSet *) Calloc(n,RxnUnMatchedSetSize)
#define RxnUnMatchedSetPntrSize sizeof(RxnUnMatchedSet **)
#define AllocPntrArrayRxnUnMatchedSet(n) (RxnUnMatchedSet **) Calloc(n,RxnUnMatchedSetPntrSize)
#define SingCopyRxnUnMatchedSet(out,in) memcpy(out,in,RxnUnMatchedSetSize)
extern RxnUnMatchedSet *CreateRxnUnMatchedSet(RxnUnMatchedSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberUnMatchedAtoms,
                                       RxnAtom *UnMatchedAtoms);

extern CHAR *GetNameRxnUnMatchedSet(RxnUnMatchedSet *str);
extern INT  GetIDRxnUnMatchedSet(RxnUnMatchedSet *str);
extern void PrintRxnUnMatchedSet(RxnUnMatchedSet *eleptr);
extern void FreeRxnUnMatchedSet(RxnUnMatchedSet *eleptr);
extern void *AllocRxnUnMatchedSet();
extern void WriteBinRxnUnMatchedSet(RxnUnMatchedSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnUnMatchedSet(RxnUnMatchedSet *eleptr, DbaseLinkedList *file);
extern void xdr_RxnUnMatchedSet(XDR *stream, char **eleptr);
extern void CopyFullRxnUnMatchedSet(RxnUnMatchedSet *newstruct, RxnUnMatchedSet *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:62:RxnBond

                    Atom1 --(RxnAtomCorrespondence) Atom Number 1
                    Atom2 --(RxnAtomCorrespondence) Atom Number 2
                     Type --(INT) The type of bond change
*/
typedef struct rxnbond RxnBond;
struct rxnbond {
     INT ID;
     CHAR *Name;
     RxnAtomCorrespondence *Atom1;
     RxnAtomCorrespondence *Atom2;
     INT  Type;
     };
#define RxnBondSize sizeof(RxnBond)
#define AllocateRxnBond (RxnBond *) Malloc(RxnBondSize)
#define AllocArrayRxnBond(n) (RxnBond *) Calloc(n,RxnBondSize)
#define RxnBondPntrSize sizeof(RxnBond **)
#define AllocPntrArrayRxnBond(n) (RxnBond **) Calloc(n,RxnBondPntrSize)
#define SingCopyRxnBond(out,in) memcpy(out,in,RxnBondSize)
extern RxnBond *CreateRxnBond(RxnBond *newstruct,
                       INT id,
                       CHAR *name,
                       RxnAtomCorrespondence *Atom1,
                       RxnAtomCorrespondence *Atom2,
                       INT  Type);

extern CHAR *GetNameRxnBond(RxnBond *str);
extern INT  GetIDRxnBond(RxnBond *str);
extern void PrintRxnBond(RxnBond *eleptr);
extern void FreeRxnBond(RxnBond *eleptr);
extern void *AllocRxnBond();
extern void WriteBinRxnBond(RxnBond *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnBond(RxnBond *eleptr, DbaseLinkedList *file);
extern void xdr_RxnBond(XDR *stream, char **eleptr);
extern void CopyFullRxnBond(RxnBond *newstruct, RxnBond *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:62:RxnBondChanges

        NumberBondChanges --(INT) The Number of bond changes
                  Changes --(RxnBond) Set of Reaction Bond Changes
*/
typedef struct rxnbondchanges RxnBondChanges;
struct rxnbondchanges {
     INT ID;
     CHAR *Name;
     INT  NumberBondChanges;
     RxnBond *Changes;
     };
#define RxnBondChangesSize sizeof(RxnBondChanges)
#define AllocateRxnBondChanges (RxnBondChanges *) Malloc(RxnBondChangesSize)
#define AllocArrayRxnBondChanges(n) (RxnBondChanges *) Calloc(n,RxnBondChangesSize)
#define RxnBondChangesPntrSize sizeof(RxnBondChanges **)
#define AllocPntrArrayRxnBondChanges(n) (RxnBondChanges **) Calloc(n,RxnBondChangesPntrSize)
#define SingCopyRxnBondChanges(out,in) memcpy(out,in,RxnBondChangesSize)
extern RxnBondChanges *CreateRxnBondChanges(RxnBondChanges *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberBondChanges,
                                     RxnBond *Changes);

extern CHAR *GetNameRxnBondChanges(RxnBondChanges *str);
extern INT  GetIDRxnBondChanges(RxnBondChanges *str);
extern void PrintRxnBondChanges(RxnBondChanges *eleptr);
extern void FreeRxnBondChanges(RxnBondChanges *eleptr);
extern void *AllocRxnBondChanges();
extern void WriteBinRxnBondChanges(RxnBondChanges *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnBondChanges(RxnBondChanges *eleptr, DbaseLinkedList *file);
extern void xdr_RxnBondChanges(XDR *stream, char **eleptr);
extern void CopyFullRxnBondChanges(RxnBondChanges *newstruct, RxnBondChanges *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:62:RxnCorrespondenceSet

            NumberOfCorrs --(INT) The Number of Correspondences
                    Corrs --(RxnAtomCorrespondence) The Correspondences
              BondChanges --(RxnBondChanges) The Set of Bond Changes
                UnMatched --(RxnUnMatchedSet) The Unmatched Reactant Atoms
*/
typedef struct rxncorrset RxnCorrespondenceSet;
struct rxncorrset {
     INT ID;
     CHAR *Name;
     INT  NumberOfCorrs;
     RxnAtomCorrespondence *Corrs;
     RxnBondChanges *BondChanges;
     RxnUnMatchedSet *UnMatched;
     };
#define RxnCorrespondenceSetSize sizeof(RxnCorrespondenceSet)
#define AllocateRxnCorrespondenceSet (RxnCorrespondenceSet *) Malloc(RxnCorrespondenceSetSize)
#define AllocArrayRxnCorrespondenceSet(n) (RxnCorrespondenceSet *) Calloc(n,RxnCorrespondenceSetSize)
#define RxnCorrespondenceSetPntrSize sizeof(RxnCorrespondenceSet **)
#define AllocPntrArrayRxnCorrespondenceSet(n) (RxnCorrespondenceSet **) Calloc(n,RxnCorrespondenceSetPntrSize)
#define SingCopyRxnCorrespondenceSet(out,in) memcpy(out,in,RxnCorrespondenceSetSize)
extern RxnCorrespondenceSet *CreateRxnCorrespondenceSet(RxnCorrespondenceSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfCorrs,
                                                 RxnAtomCorrespondence *Corrs,
                                                 RxnBondChanges *BondChanges,
                                                 RxnUnMatchedSet *UnMatched);

extern CHAR *GetNameRxnCorrespondenceSet(RxnCorrespondenceSet *str);
extern INT  GetIDRxnCorrespondenceSet(RxnCorrespondenceSet *str);
extern void PrintRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr);
extern void FreeRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr);
extern void *AllocRxnCorrespondenceSet();
extern void WriteBinRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr, DbaseLinkedList *file);
extern void xdr_RxnCorrespondenceSet(XDR *stream, char **eleptr);
extern void CopyFullRxnCorrespondenceSet(RxnCorrespondenceSet *newstruct, RxnCorrespondenceSet *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:13:ReactionDataConstants

                      Sym --(INT) The Symmetry Factor of the Products
                 Relative --(FLOAT) The Relative Rate of Reactins
                Aconstant --(FLOAT) The Arrhenius Constant
                   Energy --(FLOAT) The Activation Energy
                  TempExp --(FLOAT) The Temperature Exponent
*/
typedef struct reactiondataconstants ReactionDataConstants;
struct reactiondataconstants {
     INT ID;
     CHAR *Name;
     INT  Sym;
     FLOAT  Relative;
     FLOAT  Aconstant;
     FLOAT  Energy;
     FLOAT  TempExp;
     };
#define ReactionDataConstantsSize sizeof(ReactionDataConstants)
#define AllocateReactionDataConstants (ReactionDataConstants *) Malloc(ReactionDataConstantsSize)
#define AllocArrayReactionDataConstants(n) (ReactionDataConstants *) Calloc(n,ReactionDataConstantsSize)
#define ReactionDataConstantsPntrSize sizeof(ReactionDataConstants **)
#define AllocPntrArrayReactionDataConstants(n) (ReactionDataConstants **) Calloc(n,ReactionDataConstantsPntrSize)
#define SingCopyReactionDataConstants(out,in) memcpy(out,in,ReactionDataConstantsSize)
extern ReactionDataConstants *CreateReactionDataConstants(ReactionDataConstants *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Sym,
                                                   FLOAT  Relative,
                                                   FLOAT  Aconstant,
                                                   FLOAT  Energy,
                                                   FLOAT  TempExp);

extern CHAR *GetNameReactionDataConstants(ReactionDataConstants *str);
extern INT  GetIDReactionDataConstants(ReactionDataConstants *str);
extern void PrintReactionDataConstants(ReactionDataConstants *eleptr);
extern void FreeReactionDataConstants(ReactionDataConstants *eleptr);
extern void *AllocReactionDataConstants();
extern void WriteBinReactionDataConstants(ReactionDataConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinReactionDataConstants(ReactionDataConstants *eleptr, DbaseLinkedList *file);
extern void xdr_ReactionDataConstants(XDR *stream, char **eleptr);
extern void CopyFullReactionDataConstants(ReactionDataConstants *newstruct, ReactionDataConstants *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:13:ReactionData

                  Forward --(ReactionDataConstants) The data constants for the forward direction
                  Reverse --(ReactionDataConstants) The data constants for the reverse direction
*/
typedef struct reactiondata ReactionData;
struct reactiondata {
     INT ID;
     CHAR *Name;
     ReactionDataConstants *Forward;
     ReactionDataConstants *Reverse;
     };
#define ReactionDataSize sizeof(ReactionData)
#define AllocateReactionData (ReactionData *) Malloc(ReactionDataSize)
#define AllocArrayReactionData(n) (ReactionData *) Calloc(n,ReactionDataSize)
#define ReactionDataPntrSize sizeof(ReactionData **)
#define AllocPntrArrayReactionData(n) (ReactionData **) Calloc(n,ReactionDataPntrSize)
#define SingCopyReactionData(out,in) memcpy(out,in,ReactionDataSize)
extern ReactionData *CreateReactionData(ReactionData *newstruct,
                                 INT id,
                                 CHAR *name,
                                 ReactionDataConstants *Forward,
                                 ReactionDataConstants *Reverse);

extern CHAR *GetNameReactionData(ReactionData *str);
extern INT  GetIDReactionData(ReactionData *str);
extern void PrintReactionData(ReactionData *eleptr);
extern void FreeReactionData(ReactionData *eleptr);
extern void *AllocReactionData();
extern void WriteBinReactionData(ReactionData *eleptr, DbaseLinkedList *file);
extern INT ReadBinReactionData(ReactionData *eleptr, DbaseLinkedList *file);
extern void xdr_ReactionData(XDR *stream, char **eleptr);
extern void CopyFullReactionData(ReactionData *newstruct, ReactionData *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:63:ReactionInfo

        NumberOfReactants --(INT) The Number of reactants
         NumberOfProducts --(INT) The Number of Products
                Reactants --(INT) The set of Reactants (molecule ID's)
                 Products --(INT) The Set of Products (molecule ID's)
                TotalCorr --(RxnCorrespondenceSet) The total set of correspondences
               RxnPatCorr --(RxnCorrespondenceSet) The rxn-pattern set of correspondences
                     Data --(ReactionData) The Set  of Constants associated with a reaction
               Properties --(SetOfPropertyValues) The set of properties for the reactions
*/
typedef struct reactioninfo ReactionInfo;
struct reactioninfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactants;
     INT  NumberOfProducts;
     INT *Reactants;
     INT *Products;
     RxnCorrespondenceSet *TotalCorr;
     RxnCorrespondenceSet *RxnPatCorr;
     ReactionData *Data;
     SetOfPropertyValues *Properties;
     };
#define ReactionInfoSize sizeof(ReactionInfo)
#define AllocateReactionInfo (ReactionInfo *) Malloc(ReactionInfoSize)
#define AllocArrayReactionInfo(n) (ReactionInfo *) Calloc(n,ReactionInfoSize)
#define ReactionInfoPntrSize sizeof(ReactionInfo **)
#define AllocPntrArrayReactionInfo(n) (ReactionInfo **) Calloc(n,ReactionInfoPntrSize)
#define SingCopyReactionInfo(out,in) memcpy(out,in,ReactionInfoSize)
extern ReactionInfo *CreateReactionInfo(ReactionInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfReactants,
                                 INT  NumberOfProducts,
                                 INT *Reactants,
                                 INT *Products,
                                 RxnCorrespondenceSet *TotalCorr,
                                 RxnCorrespondenceSet *RxnPatCorr,
                                 ReactionData *Data,
                                 SetOfPropertyValues *Properties);

extern CHAR *GetNameReactionInfo(ReactionInfo *str);
extern INT  GetIDReactionInfo(ReactionInfo *str);
extern void PrintReactionInfo(ReactionInfo *eleptr);
extern void FreeReactionInfo(ReactionInfo *eleptr);
extern void *AllocReactionInfo();
extern void WriteBinReactionInfo(ReactionInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinReactionInfo(ReactionInfo *eleptr, DbaseLinkedList *file);
extern void xdr_ReactionInfo(XDR *stream, char **eleptr);
extern void CopyFullReactionInfo(ReactionInfo *newstruct, ReactionInfo *oldstruct);
/*------------------------------------------*/
/*   Reaction Structures   */
/* Structure:64:ReactionSet

        NumberOfReactions --(INT) The Number of Reactions
                Reactions --(ReactionInfo) The Reactions
            PropertyTypes --(SetOfPropertyTypes) The property types
*/
typedef struct reactionset ReactionSet;
struct reactionset {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     ReactionInfo *Reactions;
     SetOfPropertyTypes *PropertyTypes;
     };
#define ReactionSetSize sizeof(ReactionSet)
#define AllocateReactionSet (ReactionSet *) Malloc(ReactionSetSize)
#define AllocArrayReactionSet(n) (ReactionSet *) Calloc(n,ReactionSetSize)
#define ReactionSetPntrSize sizeof(ReactionSet **)
#define AllocPntrArrayReactionSet(n) (ReactionSet **) Calloc(n,ReactionSetPntrSize)
#define SingCopyReactionSet(out,in) memcpy(out,in,ReactionSetSize)
extern ReactionSet *CreateReactionSet(ReactionSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfReactions,
                               ReactionInfo *Reactions,
                               SetOfPropertyTypes *PropertyTypes);

extern CHAR *GetNameReactionSet(ReactionSet *str);
extern INT  GetIDReactionSet(ReactionSet *str);
extern void PrintReactionSet(ReactionSet *eleptr);
extern void FreeReactionSet(ReactionSet *eleptr);
extern void *AllocReactionSet();
extern void WriteBinReactionSet(ReactionSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinReactionSet(ReactionSet *eleptr, DbaseLinkedList *file);
extern void xdr_ReactionSet(XDR *stream, char **eleptr);
extern void CopyFullReactionSet(ReactionSet *newstruct, ReactionSet *oldstruct);
