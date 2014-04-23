/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:0:RxnReacProdSet

        NumberOfMolecules --(INT) The Number of Molecules
                Molecules --(INT) The set of Molecule ID's
*/
typedef struct rxnreacprodset RxnReacProdSet;
struct rxnreacprodset {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     INT *Molecules;
     };
#define RxnReacProdSetSize sizeof(RxnReacProdSet)
#define AllocateRxnReacProdSet (RxnReacProdSet *) Malloc(RxnReacProdSetSize)
#define AllocArrayRxnReacProdSet(n) (RxnReacProdSet *) Calloc(n,RxnReacProdSetSize)
#define RxnReacProdSetPntrSize sizeof(RxnReacProdSet **)
#define AllocPntrArrayRxnReacProdSet(n) (RxnReacProdSet **) Calloc(n,RxnReacProdSetPntrSize)
#define SingCopyRxnReacProdSet(out,in) memcpy(out,in,RxnReacProdSetSize)
extern RxnReacProdSet *CreateRxnReacProdSet(RxnReacProdSet *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfMolecules,
                                     INT *Molecules);

extern CHAR *GetNameRxnReacProdSet(RxnReacProdSet *str);
extern INT  GetIDRxnReacProdSet(RxnReacProdSet *str);
extern void PrintRxnReacProdSet(RxnReacProdSet *eleptr);
extern void FreeRxnReacProdSet(RxnReacProdSet *eleptr);
extern void *AllocRxnReacProdSet();
extern void WriteBinRxnReacProdSet(RxnReacProdSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinRxnReacProdSet(RxnReacProdSet *eleptr, DbaseLinkedList *file);
extern void xdr_RxnReacProdSet(XDR *stream, char **eleptr);
extern void CopyFullRxnReacProdSet(RxnReacProdSet *newstruct, RxnReacProdSet *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:1:MechanismReaction

                Reactants --(RxnReacProdSet) The set of Reactant Molecules
                 Products --(RxnReacProdSet) The set of Product Molecules
                  Forward --(ArrheniusFormValue) The Forward Rate Constant
         ForwardReference --(STRING) Forward Rate Reference
                  Reverse --(ArrheniusFormValue) The Reverse Rate Constant
         ReverseReference --(STRING) Reverse Rate Reference
                   Values --(SetOfPropertyValues) Additional Information Needed by a reaction
*/
typedef struct mechanismreaction MechanismReaction;
struct mechanismreaction {
     INT ID;
     CHAR *Name;
     RxnReacProdSet *Reactants;
     RxnReacProdSet *Products;
     ArrheniusFormValue *Forward;
     STRING *ForwardReference;
     ArrheniusFormValue *Reverse;
     STRING *ReverseReference;
     SetOfPropertyValues *Values;
     };
#define MechanismReactionSize sizeof(MechanismReaction)
#define AllocateMechanismReaction (MechanismReaction *) Malloc(MechanismReactionSize)
#define AllocArrayMechanismReaction(n) (MechanismReaction *) Calloc(n,MechanismReactionSize)
#define MechanismReactionPntrSize sizeof(MechanismReaction **)
#define AllocPntrArrayMechanismReaction(n) (MechanismReaction **) Calloc(n,MechanismReactionPntrSize)
#define SingCopyMechanismReaction(out,in) memcpy(out,in,MechanismReactionSize)
extern MechanismReaction *CreateMechanismReaction(MechanismReaction *newstruct,
                                           INT id,
                                           CHAR *name,
                                           RxnReacProdSet *Reactants,
                                           RxnReacProdSet *Products,
                                           ArrheniusFormValue *Forward,
                                           STRING *ForwardReference,
                                           ArrheniusFormValue *Reverse,
                                           STRING *ReverseReference,
                                           SetOfPropertyValues *Values);

extern CHAR *GetNameMechanismReaction(MechanismReaction *str);
extern INT  GetIDMechanismReaction(MechanismReaction *str);
extern void PrintMechanismReaction(MechanismReaction *eleptr);
extern void FreeMechanismReaction(MechanismReaction *eleptr);
extern void *AllocMechanismReaction();
extern void WriteBinMechanismReaction(MechanismReaction *eleptr, DbaseLinkedList *file);
extern INT ReadBinMechanismReaction(MechanismReaction *eleptr, DbaseLinkedList *file);
extern void xdr_MechanismReaction(XDR *stream, char **eleptr);
extern void CopyFullMechanismReaction(MechanismReaction *newstruct, MechanismReaction *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:2:MechanismMolecule

          AbbreviatedName --(STRING) The Smaller (though unique) name - to fit more on a line
          ThermoConstants --(ChemkinThermoRead) The Thermodynamic Constants (In Chemkin JANAF form)
          ThermoReference --(STRING) The Reference for the Constants
              Equilibrium --(ArrheniusFormValue) The Equilibrium Constant (If used to compute reverse reaction)
               AtomCounts --(MoleculeAtomCounts) The summary of Atom Counts
                   Values --(SetOfPropertyValues) Additional Information Needed by a molecule
*/
typedef struct mechanismmolecule MechanismMolecule;
struct mechanismmolecule {
     INT ID;
     CHAR *Name;
     STRING *AbbreviatedName;
     ChemkinThermoRead *ThermoConstants;
     STRING *ThermoReference;
     ArrheniusFormValue *Equilibrium;
     MoleculeAtomCounts *AtomCounts;
     SetOfPropertyValues *Values;
     };
#define MechanismMoleculeSize sizeof(MechanismMolecule)
#define AllocateMechanismMolecule (MechanismMolecule *) Malloc(MechanismMoleculeSize)
#define AllocArrayMechanismMolecule(n) (MechanismMolecule *) Calloc(n,MechanismMoleculeSize)
#define MechanismMoleculePntrSize sizeof(MechanismMolecule **)
#define AllocPntrArrayMechanismMolecule(n) (MechanismMolecule **) Calloc(n,MechanismMoleculePntrSize)
#define SingCopyMechanismMolecule(out,in) memcpy(out,in,MechanismMoleculeSize)
extern MechanismMolecule *CreateMechanismMolecule(MechanismMolecule *newstruct,
                                           INT id,
                                           CHAR *name,
                                           STRING *AbbreviatedName,
                                           ChemkinThermoRead *ThermoConstants,
                                           STRING *ThermoReference,
                                           ArrheniusFormValue *Equilibrium,
                                           MoleculeAtomCounts *AtomCounts,
                                           SetOfPropertyValues *Values);

extern CHAR *GetNameMechanismMolecule(MechanismMolecule *str);
extern INT  GetIDMechanismMolecule(MechanismMolecule *str);
extern void PrintMechanismMolecule(MechanismMolecule *eleptr);
extern void FreeMechanismMolecule(MechanismMolecule *eleptr);
extern void *AllocMechanismMolecule();
extern void WriteBinMechanismMolecule(MechanismMolecule *eleptr, DbaseLinkedList *file);
extern INT ReadBinMechanismMolecule(MechanismMolecule *eleptr, DbaseLinkedList *file);
extern void xdr_MechanismMolecule(XDR *stream, char **eleptr);
extern void CopyFullMechanismMolecule(MechanismMolecule *newstruct, MechanismMolecule *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:3:MechanismMoleculeSet

        NumberOfMolecules --(INT) The Number of molecules
                Molecules --(MechanismMolecule) The set of Molecules
                PropTypes --(SetOfPropertyTypes) The property types of the molecules
*/
typedef struct mechanismmolset MechanismMoleculeSet;
struct mechanismmolset {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     MechanismMolecule *Molecules;
     SetOfPropertyTypes *PropTypes;
     };
#define MechanismMoleculeSetSize sizeof(MechanismMoleculeSet)
#define AllocateMechanismMoleculeSet (MechanismMoleculeSet *) Malloc(MechanismMoleculeSetSize)
#define AllocArrayMechanismMoleculeSet(n) (MechanismMoleculeSet *) Calloc(n,MechanismMoleculeSetSize)
#define MechanismMoleculeSetPntrSize sizeof(MechanismMoleculeSet **)
#define AllocPntrArrayMechanismMoleculeSet(n) (MechanismMoleculeSet **) Calloc(n,MechanismMoleculeSetPntrSize)
#define SingCopyMechanismMoleculeSet(out,in) memcpy(out,in,MechanismMoleculeSetSize)
extern MechanismMoleculeSet *CreateMechanismMoleculeSet(MechanismMoleculeSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfMolecules,
                                                 MechanismMolecule *Molecules,
                                                 SetOfPropertyTypes *PropTypes);

extern CHAR *GetNameMechanismMoleculeSet(MechanismMoleculeSet *str);
extern INT  GetIDMechanismMoleculeSet(MechanismMoleculeSet *str);
extern void PrintMechanismMoleculeSet(MechanismMoleculeSet *eleptr);
extern void FreeMechanismMoleculeSet(MechanismMoleculeSet *eleptr);
extern void *AllocMechanismMoleculeSet();
extern void WriteBinMechanismMoleculeSet(MechanismMoleculeSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinMechanismMoleculeSet(MechanismMoleculeSet *eleptr, DbaseLinkedList *file);
extern void xdr_MechanismMoleculeSet(XDR *stream, char **eleptr);
extern void CopyFullMechanismMoleculeSet(MechanismMoleculeSet *newstruct, MechanismMoleculeSet *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:4:MechanismReactionSet

        NumberOfReactions --(INT) The Number of reactions
                Reactions --(MechanismReaction) The set of Reactions
                PropTypes --(SetOfPropertyTypes) The property types of the reactions
*/
typedef struct mechanismreactionset MechanismReactionSet;
struct mechanismreactionset {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     MechanismReaction *Reactions;
     SetOfPropertyTypes *PropTypes;
     };
#define MechanismReactionSetSize sizeof(MechanismReactionSet)
#define AllocateMechanismReactionSet (MechanismReactionSet *) Malloc(MechanismReactionSetSize)
#define AllocArrayMechanismReactionSet(n) (MechanismReactionSet *) Calloc(n,MechanismReactionSetSize)
#define MechanismReactionSetPntrSize sizeof(MechanismReactionSet **)
#define AllocPntrArrayMechanismReactionSet(n) (MechanismReactionSet **) Calloc(n,MechanismReactionSetPntrSize)
#define SingCopyMechanismReactionSet(out,in) memcpy(out,in,MechanismReactionSetSize)
extern MechanismReactionSet *CreateMechanismReactionSet(MechanismReactionSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfReactions,
                                                 MechanismReaction *Reactions,
                                                 SetOfPropertyTypes *PropTypes);

extern CHAR *GetNameMechanismReactionSet(MechanismReactionSet *str);
extern INT  GetIDMechanismReactionSet(MechanismReactionSet *str);
extern void PrintMechanismReactionSet(MechanismReactionSet *eleptr);
extern void FreeMechanismReactionSet(MechanismReactionSet *eleptr);
extern void *AllocMechanismReactionSet();
extern void WriteBinMechanismReactionSet(MechanismReactionSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinMechanismReactionSet(MechanismReactionSet *eleptr, DbaseLinkedList *file);
extern void xdr_MechanismReactionSet(XDR *stream, char **eleptr);
extern void CopyFullMechanismReactionSet(MechanismReactionSet *newstruct, MechanismReactionSet *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:2:DetailedMechanism

                   RxnSet --(MechanismReactionSet) The set of reactions
                   MolSet --(MechanismMoleculeSet) The set of molecules
                Molecules --(MoleculeSet) Additional Molecules (not in database)
                Reactions --(ReactionSet) Additional Reactions (not in database)
                   Values --(SetOfPropertyValues) Additional Information Needed by a mechanism
*/
typedef struct detailedmechanism DetailedMechanism;
struct detailedmechanism {
     INT ID;
     CHAR *Name;
     MechanismReactionSet *RxnSet;
     MechanismMoleculeSet *MolSet;
     MoleculeSet *Molecules;
     ReactionSet *Reactions;
     SetOfPropertyValues *Values;
     };
#define DetailedMechanismSize sizeof(DetailedMechanism)
#define AllocateDetailedMechanism (DetailedMechanism *) Malloc(DetailedMechanismSize)
#define AllocArrayDetailedMechanism(n) (DetailedMechanism *) Calloc(n,DetailedMechanismSize)
#define DetailedMechanismPntrSize sizeof(DetailedMechanism **)
#define AllocPntrArrayDetailedMechanism(n) (DetailedMechanism **) Calloc(n,DetailedMechanismPntrSize)
#define SingCopyDetailedMechanism(out,in) memcpy(out,in,DetailedMechanismSize)
extern DetailedMechanism *CreateDetailedMechanism(DetailedMechanism *newstruct,
                                           INT id,
                                           CHAR *name,
                                           MechanismReactionSet *RxnSet,
                                           MechanismMoleculeSet *MolSet,
                                           MoleculeSet *Molecules,
                                           ReactionSet *Reactions,
                                           SetOfPropertyValues *Values);

extern CHAR *GetNameDetailedMechanism(DetailedMechanism *str);
extern INT  GetIDDetailedMechanism(DetailedMechanism *str);
extern void PrintDetailedMechanism(DetailedMechanism *eleptr);
extern void FreeDetailedMechanism(DetailedMechanism *eleptr);
extern void *AllocDetailedMechanism();
extern void WriteBinDetailedMechanism(DetailedMechanism *eleptr, DbaseLinkedList *file);
extern INT ReadBinDetailedMechanism(DetailedMechanism *eleptr, DbaseLinkedList *file);
extern void xdr_DetailedMechanism(XDR *stream, char **eleptr);
extern void CopyFullDetailedMechanism(DetailedMechanism *newstruct, DetailedMechanism *oldstruct);
/*------------------------------------------*/
/*   Structures Defining a Mechanism   */
/* Structure:6:SetOfDetailedMechanisms

       NumberOfMechanisms --(INT) The number of current mechanisms
               Mechanisms --(DetailedMechanism) The set of Mechanisms
                PropTypes --(SetOfPropertyTypes) The property types of the mechansim
*/
typedef struct setofdetailedmechanisms SetOfDetailedMechanisms;
struct setofdetailedmechanisms {
     INT ID;
     CHAR *Name;
     INT  NumberOfMechanisms;
     DetailedMechanism *Mechanisms;
     SetOfPropertyTypes *PropTypes;
     };
#define SetOfDetailedMechanismsSize sizeof(SetOfDetailedMechanisms)
#define AllocateSetOfDetailedMechanisms (SetOfDetailedMechanisms *) Malloc(SetOfDetailedMechanismsSize)
#define AllocArraySetOfDetailedMechanisms(n) (SetOfDetailedMechanisms *) Calloc(n,SetOfDetailedMechanismsSize)
#define SetOfDetailedMechanismsPntrSize sizeof(SetOfDetailedMechanisms **)
#define AllocPntrArraySetOfDetailedMechanisms(n) (SetOfDetailedMechanisms **) Calloc(n,SetOfDetailedMechanismsPntrSize)
#define SingCopySetOfDetailedMechanisms(out,in) memcpy(out,in,SetOfDetailedMechanismsSize)
extern SetOfDetailedMechanisms *CreateSetOfDetailedMechanisms(SetOfDetailedMechanisms *newstruct,
INT id,
CHAR *name,
INT  NumberOfMechanisms,
DetailedMechanism *Mechanisms,
SetOfPropertyTypes *PropTypes);

extern CHAR *GetNameSetOfDetailedMechanisms(SetOfDetailedMechanisms *str);
extern INT  GetIDSetOfDetailedMechanisms(SetOfDetailedMechanisms *str);
extern void PrintSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr);
extern void FreeSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr);
extern void *AllocSetOfDetailedMechanisms();
extern void WriteBinSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfDetailedMechanisms(XDR *stream, char **eleptr);
extern void CopyFullSetOfDetailedMechanisms(SetOfDetailedMechanisms *newstruct, SetOfDetailedMechanisms *oldstruct);
