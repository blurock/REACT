/*------------------------------------------*/
/*   Chain Sequence Structures   */
/* Structure:0:AuxMolecules

        NumberOfMolecules --(INT) The number of molecules
                Molecules --(INT) The set of molecules
*/
typedef struct auxmolecules AuxMolecules;
struct auxmolecules {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     INT *Molecules;
     };
#define AuxMoleculesSize sizeof(AuxMolecules)
#define AllocateAuxMolecules (AuxMolecules *) Malloc(AuxMoleculesSize)
#define AllocArrayAuxMolecules(n) (AuxMolecules *) Calloc(n,AuxMoleculesSize)
#define AuxMoleculesPntrSize sizeof(AuxMolecules **)
#define AllocPntrArrayAuxMolecules(n) (AuxMolecules **) Calloc(n,AuxMoleculesPntrSize)
#define SingCopyAuxMolecules(out,in) memcpy(out,in,AuxMoleculesSize)
extern AuxMolecules *CreateAuxMolecules(AuxMolecules *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfMolecules,
                                 INT *Molecules);

extern CHAR *GetNameAuxMolecules(AuxMolecules *str);
extern INT  GetIDAuxMolecules(AuxMolecules *str);
extern void PrintAuxMolecules(AuxMolecules *eleptr);
extern void FreeAuxMolecules(AuxMolecules *eleptr);
extern void *AllocAuxMolecules();
extern void WriteBinAuxMolecules(AuxMolecules *eleptr, DbaseLinkedList *file);
extern INT ReadBinAuxMolecules(AuxMolecules *eleptr, DbaseLinkedList *file);
extern void xdr_AuxMolecules(XDR *stream, char **eleptr);
extern void CopyFullAuxMolecules(AuxMolecules *newstruct, AuxMolecules *oldstruct);
/*------------------------------------------*/
/*   Chain Sequence Structures   */
/* Structure:1:ChainSequenceElement

                Molecules --(SetOfGraphs) The set of auxiliary molecule for reaction
                Reactions --(TransformSet) The set of Transforms
*/
typedef struct chainsequenceelement ChainSequenceElement;
struct chainsequenceelement {
     INT ID;
     CHAR *Name;
     SetOfGraphs *Molecules;
     TransformSet *Reactions;
     };
#define ChainSequenceElementSize sizeof(ChainSequenceElement)
#define AllocateChainSequenceElement (ChainSequenceElement *) Malloc(ChainSequenceElementSize)
#define AllocArrayChainSequenceElement(n) (ChainSequenceElement *) Calloc(n,ChainSequenceElementSize)
#define ChainSequenceElementPntrSize sizeof(ChainSequenceElement **)
#define AllocPntrArrayChainSequenceElement(n) (ChainSequenceElement **) Calloc(n,ChainSequenceElementPntrSize)
#define SingCopyChainSequenceElement(out,in) memcpy(out,in,ChainSequenceElementSize)
extern ChainSequenceElement *CreateChainSequenceElement(ChainSequenceElement *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 SetOfGraphs *Molecules,
                                                 TransformSet *Reactions);

extern CHAR *GetNameChainSequenceElement(ChainSequenceElement *str);
extern INT  GetIDChainSequenceElement(ChainSequenceElement *str);
extern void PrintChainSequenceElement(ChainSequenceElement *eleptr);
extern void FreeChainSequenceElement(ChainSequenceElement *eleptr);
extern void *AllocChainSequenceElement();
extern void WriteBinChainSequenceElement(ChainSequenceElement *eleptr, DbaseLinkedList *file);
extern INT ReadBinChainSequenceElement(ChainSequenceElement *eleptr, DbaseLinkedList *file);
extern void xdr_ChainSequenceElement(XDR *stream, char **eleptr);
extern void CopyFullChainSequenceElement(ChainSequenceElement *newstruct, ChainSequenceElement *oldstruct);
/*------------------------------------------*/
/*   Chain Sequence Structures   */
/* Structure:3:ReadChainReactionStep

                Reactions --(ReadInReactionSet) The set of reaction patterns
                Molecules --(ReadInMoleculeSet) The set of step molecules
*/
typedef struct readchainreactionstep ReadChainReactionStep;
struct readchainreactionstep {
     INT ID;
     CHAR *Name;
     ReadInReactionSet *Reactions;
     ReadInMoleculeSet *Molecules;
     };
#define ReadChainReactionStepSize sizeof(ReadChainReactionStep)
#define AllocateReadChainReactionStep (ReadChainReactionStep *) Malloc(ReadChainReactionStepSize)
#define AllocArrayReadChainReactionStep(n) (ReadChainReactionStep *) Calloc(n,ReadChainReactionStepSize)
#define ReadChainReactionStepPntrSize sizeof(ReadChainReactionStep **)
#define AllocPntrArrayReadChainReactionStep(n) (ReadChainReactionStep **) Calloc(n,ReadChainReactionStepPntrSize)
#define SingCopyReadChainReactionStep(out,in) memcpy(out,in,ReadChainReactionStepSize)
extern ReadChainReactionStep *CreateReadChainReactionStep(ReadChainReactionStep *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   ReadInReactionSet *Reactions,
                                                   ReadInMoleculeSet *Molecules);

extern CHAR *GetNameReadChainReactionStep(ReadChainReactionStep *str);
extern INT  GetIDReadChainReactionStep(ReadChainReactionStep *str);
extern void PrintReadChainReactionStep(ReadChainReactionStep *eleptr);
extern void FreeReadChainReactionStep(ReadChainReactionStep *eleptr);
extern void *AllocReadChainReactionStep();
extern void WriteBinReadChainReactionStep(ReadChainReactionStep *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadChainReactionStep(ReadChainReactionStep *eleptr, DbaseLinkedList *file);
extern void xdr_ReadChainReactionStep(XDR *stream, char **eleptr);
extern void CopyFullReadChainReactionStep(ReadChainReactionStep *newstruct, ReadChainReactionStep *oldstruct);
/*------------------------------------------*/
/*   Chain Sequence Structures   */
/* Structure:2:ReadChainSet

            NumberOfSteps --(INT) The number in the sequence
                    Steps --(ReadChainReactionStep) The set of steps
           ExtraMolecules --(ReadInMoleculeSet) Auxiliary molecules for all steps
                Molecules --(ReadInMoleculeSet) The set of molecules
                Reactions --(ReadInReactionSet) The set of reactions
*/
typedef struct readchainset ReadChainSet;
struct readchainset {
     INT ID;
     CHAR *Name;
     INT  NumberOfSteps;
     ReadChainReactionStep *Steps;
     ReadInMoleculeSet *ExtraMolecules;
     ReadInMoleculeSet *Molecules;
     ReadInReactionSet *Reactions;
     };
#define ReadChainSetSize sizeof(ReadChainSet)
#define AllocateReadChainSet (ReadChainSet *) Malloc(ReadChainSetSize)
#define AllocArrayReadChainSet(n) (ReadChainSet *) Calloc(n,ReadChainSetSize)
#define ReadChainSetPntrSize sizeof(ReadChainSet **)
#define AllocPntrArrayReadChainSet(n) (ReadChainSet **) Calloc(n,ReadChainSetPntrSize)
#define SingCopyReadChainSet(out,in) memcpy(out,in,ReadChainSetSize)
extern ReadChainSet *CreateReadChainSet(ReadChainSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfSteps,
                                 ReadChainReactionStep *Steps,
                                 ReadInMoleculeSet *ExtraMolecules,
                                 ReadInMoleculeSet *Molecules,
                                 ReadInReactionSet *Reactions);

extern CHAR *GetNameReadChainSet(ReadChainSet *str);
extern INT  GetIDReadChainSet(ReadChainSet *str);
extern void PrintReadChainSet(ReadChainSet *eleptr);
extern void FreeReadChainSet(ReadChainSet *eleptr);
extern void *AllocReadChainSet();
extern void WriteBinReadChainSet(ReadChainSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinReadChainSet(ReadChainSet *eleptr, DbaseLinkedList *file);
extern void xdr_ReadChainSet(XDR *stream, char **eleptr);
extern void CopyFullReadChainSet(ReadChainSet *newstruct, ReadChainSet *oldstruct);
/*------------------------------------------*/
/*   Chain Sequence Structures   */
/* Structure:2:ChainSequence

            NumberOfSteps --(INT) The number in the Sequence
                    Steps --(ChainSequenceElement) The set of steps
                Molecules --(SetOfGraphs) Auxiliary molecules for all steps
*/
typedef struct chainsequence ChainSequence;
struct chainsequence {
     INT ID;
     CHAR *Name;
     INT  NumberOfSteps;
     ChainSequenceElement *Steps;
     SetOfGraphs *Molecules;
     };
#define ChainSequenceSize sizeof(ChainSequence)
#define AllocateChainSequence (ChainSequence *) Malloc(ChainSequenceSize)
#define AllocArrayChainSequence(n) (ChainSequence *) Calloc(n,ChainSequenceSize)
#define ChainSequencePntrSize sizeof(ChainSequence **)
#define AllocPntrArrayChainSequence(n) (ChainSequence **) Calloc(n,ChainSequencePntrSize)
#define SingCopyChainSequence(out,in) memcpy(out,in,ChainSequenceSize)
extern ChainSequence *CreateChainSequence(ChainSequence *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfSteps,
                                   ChainSequenceElement *Steps,
                                   SetOfGraphs *Molecules);

extern CHAR *GetNameChainSequence(ChainSequence *str);
extern INT  GetIDChainSequence(ChainSequence *str);
extern void PrintChainSequence(ChainSequence *eleptr);
extern void FreeChainSequence(ChainSequence *eleptr);
extern void *AllocChainSequence();
extern void WriteBinChainSequence(ChainSequence *eleptr, DbaseLinkedList *file);
extern INT ReadBinChainSequence(ChainSequence *eleptr, DbaseLinkedList *file);
extern void xdr_ChainSequence(XDR *stream, char **eleptr);
extern void CopyFullChainSequence(ChainSequence *newstruct, ChainSequence *oldstruct);
