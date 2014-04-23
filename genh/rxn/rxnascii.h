/*------------------------------------------*/
/*   Mecahiism Structures   */
/* Structure:13:MolFileReaction

        NumberOfReactants --(INT) The Number of reactants
         NumberOfProducts --(INT) The Number of Products
                Reactants --(MolFileMolecule) The Set of Reactants
                 Products --(MolFileMolecule) The Set of Products
               Properties --(ASCIIProperties) The Primitive Reaction Properties
*/
typedef struct reactionmolfile MolFileReaction;
struct reactionmolfile {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactants;
     INT  NumberOfProducts;
     MolFileMolecule *Reactants;
     MolFileMolecule *Products;
     ASCIIProperties *Properties;
     };
#define MolFileReactionSize sizeof(MolFileReaction)
#define AllocateMolFileReaction (MolFileReaction *) Malloc(MolFileReactionSize)
#define AllocArrayMolFileReaction(n) (MolFileReaction *) Calloc(n,MolFileReactionSize)
#define MolFileReactionPntrSize sizeof(MolFileReaction **)
#define AllocPntrArrayMolFileReaction(n) (MolFileReaction **) Calloc(n,MolFileReactionPntrSize)
#define SingCopyMolFileReaction(out,in) memcpy(out,in,MolFileReactionSize)
extern MolFileReaction *CreateMolFileReaction(MolFileReaction *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfReactants,
                                       INT  NumberOfProducts,
                                       MolFileMolecule *Reactants,
                                       MolFileMolecule *Products,
                                       ASCIIProperties *Properties);

extern CHAR *GetNameMolFileReaction(MolFileReaction *str);
extern INT  GetIDMolFileReaction(MolFileReaction *str);
extern void PrintMolFileReaction(MolFileReaction *eleptr);
extern void FreeMolFileReaction(MolFileReaction *eleptr);
extern void *AllocMolFileReaction();
extern void WriteBinMolFileReaction(MolFileReaction *eleptr, DbaseLinkedList *file);
extern INT ReadBinMolFileReaction(MolFileReaction *eleptr, DbaseLinkedList *file);
extern void xdr_MolFileReaction(XDR *stream, char **eleptr);
extern void CopyFullMolFileReaction(MolFileReaction *newstruct, MolFileReaction *oldstruct);
/*------------------------------------------*/
/*   Mecahiism Structures   */
/* Structure:2:ASCIIReaction

                Reactants --(ReadInMoleculeSet) The set of Reactant Molecules
             ReactionType --(INT) Reaction Types (forward, reverse, equilibrium)
                 Products --(ReadInMoleculeSet) The set of Product Molecules
               Properties --(ASCIIProperties) The set of properties
*/
typedef struct asciireaction ASCIIReaction;
struct asciireaction {
     INT ID;
     CHAR *Name;
     ReadInMoleculeSet *Reactants;
     INT  ReactionType;
     ReadInMoleculeSet *Products;
     ASCIIProperties *Properties;
     };
#define ASCIIReactionSize sizeof(ASCIIReaction)
#define AllocateASCIIReaction (ASCIIReaction *) Malloc(ASCIIReactionSize)
#define AllocArrayASCIIReaction(n) (ASCIIReaction *) Calloc(n,ASCIIReactionSize)
#define ASCIIReactionPntrSize sizeof(ASCIIReaction **)
#define AllocPntrArrayASCIIReaction(n) (ASCIIReaction **) Calloc(n,ASCIIReactionPntrSize)
#define SingCopyASCIIReaction(out,in) memcpy(out,in,ASCIIReactionSize)
extern ASCIIReaction *CreateASCIIReaction(ASCIIReaction *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ReadInMoleculeSet *Reactants,
                                   INT  ReactionType,
                                   ReadInMoleculeSet *Products,
                                   ASCIIProperties *Properties);

extern CHAR *GetNameASCIIReaction(ASCIIReaction *str);
extern INT  GetIDASCIIReaction(ASCIIReaction *str);
extern void PrintASCIIReaction(ASCIIReaction *eleptr);
extern void FreeASCIIReaction(ASCIIReaction *eleptr);
extern void *AllocASCIIReaction();
extern void WriteBinASCIIReaction(ASCIIReaction *eleptr, DbaseLinkedList *file);
extern INT ReadBinASCIIReaction(ASCIIReaction *eleptr, DbaseLinkedList *file);
extern void xdr_ASCIIReaction(XDR *stream, char **eleptr);
extern void CopyFullASCIIReaction(ASCIIReaction *newstruct, ASCIIReaction *oldstruct);
/*------------------------------------------*/
/*   Mecahiism Structures   */
/* Structure:3:ASCIIReactionSet

        NumberOfReactions --(INT) The number of reactions
                Reactions --(ASCIIReaction) The set of reactions
*/
typedef struct asciireactionset ASCIIReactionSet;
struct asciireactionset {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     ASCIIReaction *Reactions;
     };
#define ASCIIReactionSetSize sizeof(ASCIIReactionSet)
#define AllocateASCIIReactionSet (ASCIIReactionSet *) Malloc(ASCIIReactionSetSize)
#define AllocArrayASCIIReactionSet(n) (ASCIIReactionSet *) Calloc(n,ASCIIReactionSetSize)
#define ASCIIReactionSetPntrSize sizeof(ASCIIReactionSet **)
#define AllocPntrArrayASCIIReactionSet(n) (ASCIIReactionSet **) Calloc(n,ASCIIReactionSetPntrSize)
#define SingCopyASCIIReactionSet(out,in) memcpy(out,in,ASCIIReactionSetSize)
extern ASCIIReactionSet *CreateASCIIReactionSet(ASCIIReactionSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfReactions,
                                         ASCIIReaction *Reactions);

extern CHAR *GetNameASCIIReactionSet(ASCIIReactionSet *str);
extern INT  GetIDASCIIReactionSet(ASCIIReactionSet *str);
extern void PrintASCIIReactionSet(ASCIIReactionSet *eleptr);
extern void FreeASCIIReactionSet(ASCIIReactionSet *eleptr);
extern void *AllocASCIIReactionSet();
extern void WriteBinASCIIReactionSet(ASCIIReactionSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinASCIIReactionSet(ASCIIReactionSet *eleptr, DbaseLinkedList *file);
extern void xdr_ASCIIReactionSet(XDR *stream, char **eleptr);
extern void CopyFullASCIIReactionSet(ASCIIReactionSet *newstruct, ASCIIReactionSet *oldstruct);
/*------------------------------------------*/
/*   Mecahiism Structures   */
/* Structure:3:ReadInReaction

*/
typedef struct readinreaction ReadInReaction;
struct readinreaction {
     INT ID;
     CHAR *Name;
     };
#define ReadInReactionSize sizeof(ReadInReaction)
#define AllocateReadInReaction (ReadInReaction *) Malloc(ReadInReactionSize)
#define AllocArrayReadInReaction(n) (ReadInReaction *) Calloc(n,ReadInReactionSize)
#define ReadInReactionPntrSize sizeof(ReadInReaction **)
#define AllocPntrArrayReadInReaction(n) (ReadInReaction **) Calloc(n,ReadInReactionPntrSize)
#define SingCopyReadInReaction(out,in) memcpy(out,in,ReadInReactionSize)
extern ReadInReaction *CreateReadInReaction(ReadInReaction *newstruct,
                                     INT id,
                                     CHAR *name);

extern CHAR *GetNameReadInReaction(ReadInReaction *str);
extern INT  GetIDReadInReaction(ReadInReaction *str);
extern void PrintReadInReaction(ReadInReaction *eleptr);
extern void FreeReadInReaction(ReadInReaction *eleptr);
extern void *AllocReadInReaction();
extern void WriteBinReadInReaction(ReadInReaction *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadInReaction(ReadInReaction *eleptr, DbaseLinkedList *file);
extern void xdr_ReadInReaction(XDR *stream, char **eleptr);
extern void CopyFullReadInReaction(ReadInReaction *newstruct, ReadInReaction *oldstruct);
/*------------------------------------------*/
/*   Mecahiism Structures   */
/* Structure:4:ReadInReactionSet

        NumberOfReactions --(INT) The number of reactions
                Reactions --(ReadInReaction) The set of reactions
*/
typedef struct readinreactionset ReadInReactionSet;
struct readinreactionset {
     INT ID;
     CHAR *Name;
     INT  NumberOfReactions;
     ReadInReaction *Reactions;
     };
#define ReadInReactionSetSize sizeof(ReadInReactionSet)
#define AllocateReadInReactionSet (ReadInReactionSet *) Malloc(ReadInReactionSetSize)
#define AllocArrayReadInReactionSet(n) (ReadInReactionSet *) Calloc(n,ReadInReactionSetSize)
#define ReadInReactionSetPntrSize sizeof(ReadInReactionSet **)
#define AllocPntrArrayReadInReactionSet(n) (ReadInReactionSet **) Calloc(n,ReadInReactionSetPntrSize)
#define SingCopyReadInReactionSet(out,in) memcpy(out,in,ReadInReactionSetSize)
extern ReadInReactionSet *CreateReadInReactionSet(ReadInReactionSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfReactions,
                                           ReadInReaction *Reactions);

extern CHAR *GetNameReadInReactionSet(ReadInReactionSet *str);
extern INT  GetIDReadInReactionSet(ReadInReactionSet *str);
extern void PrintReadInReactionSet(ReadInReactionSet *eleptr);
extern void FreeReadInReactionSet(ReadInReactionSet *eleptr);
extern void *AllocReadInReactionSet();
extern void WriteBinReadInReactionSet(ReadInReactionSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadInReactionSet(ReadInReactionSet *eleptr, DbaseLinkedList *file);
extern void xdr_ReadInReactionSet(XDR *stream, char **eleptr);
extern void CopyFullReadInReactionSet(ReadInReactionSet *newstruct, ReadInReactionSet *oldstruct);
