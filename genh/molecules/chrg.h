/*------------------------------------------*/
/*   Structures for Charge Routines   */
/* Structure:30:AtomElectronic

             AtomicNumber --(INT) Atomic Number
                   Shells --(FLOAT) The full integral charge on the atom
                NOccupied --(INT) The number of electrons on the atom
               NElectrons --(FLOAT) An array with the number of electrons in each shell.
                   Charge --(FLOAT) The number of shells which are occupied
        Electronegativity --(FLOAT) The calculated electronegativity
                Screening --(FLOAT) The sigma screening charge
           CovalentRadius --(FLOAT) The covalent radius of the atom
            NuclearCharge --(FLOAT) The effective nuclear charge
           ResidualCharge --(FLOAT) The residual charge on the atom
                     Beta --(FLOAT) Screening factor
                     ZEff --(FLOAT) Effective Atom Charge
           NumberOfShells --(INT) Number of Shells
           Polarizability --(FLOAT) The Polarizability
*/
typedef struct atomelectronic AtomElectronic;
struct atomelectronic {
     INT ID;
     CHAR *Name;
     INT  AtomicNumber;
     FLOAT *Shells;
     INT  NOccupied;
     FLOAT  NElectrons;
     FLOAT  Charge;
     FLOAT  Electronegativity;
     FLOAT  Screening;
     FLOAT  CovalentRadius;
     FLOAT  NuclearCharge;
     FLOAT  ResidualCharge;
     FLOAT  Beta;
     FLOAT  ZEff;
     INT  NumberOfShells;
     FLOAT  Polarizability;
     };
#define AtomElectronicSize sizeof(AtomElectronic)
#define AllocateAtomElectronic (AtomElectronic *) Malloc(AtomElectronicSize)
#define AllocArrayAtomElectronic(n) (AtomElectronic *) Calloc(n,AtomElectronicSize)
#define AtomElectronicPntrSize sizeof(AtomElectronic **)
#define AllocPntrArrayAtomElectronic(n) (AtomElectronic **) Calloc(n,AtomElectronicPntrSize)
#define SingCopyAtomElectronic(out,in) memcpy(out,in,AtomElectronicSize)
extern AtomElectronic *CreateAtomElectronic(AtomElectronic *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  AtomicNumber,
                                     FLOAT *Shells,
                                     INT  NOccupied,
                                     FLOAT  NElectrons,
                                     FLOAT  Charge,
                                     FLOAT  Electronegativity,
                                     FLOAT  Screening,
                                     FLOAT  CovalentRadius,
                                     FLOAT  NuclearCharge,
                                     FLOAT  ResidualCharge,
                                     FLOAT  Beta,
                                     FLOAT  ZEff,
                                     INT  NumberOfShells,
                                     FLOAT  Polarizability);

extern CHAR *GetNameAtomElectronic(AtomElectronic *str);
extern INT  GetIDAtomElectronic(AtomElectronic *str);
extern void PrintAtomElectronic(AtomElectronic *eleptr);
extern void FreeAtomElectronic(AtomElectronic *eleptr);
extern void *AllocAtomElectronic();
extern void WriteBinAtomElectronic(AtomElectronic *eleptr, DbaseLinkedList *file);
extern INT ReadBinAtomElectronic(AtomElectronic *eleptr, DbaseLinkedList *file);
extern void xdr_AtomElectronic(XDR *stream, char **eleptr);
extern void CopyFullAtomElectronic(AtomElectronic *newstruct, AtomElectronic *oldstruct);
/*------------------------------------------*/
/*   Structures for Charge Routines   */
/* Structure:42:Resonance

            NumberOfAtoms --(INT) Number of atoms in set
                    Atoms --(INT) The set of labels for resonant atoms
*/
typedef struct resonantset Resonance;
struct resonantset {
     INT ID;
     CHAR *Name;
     INT  NumberOfAtoms;
     INT *Atoms;
     };
#define ResonanceSize sizeof(Resonance)
#define AllocateResonance (Resonance *) Malloc(ResonanceSize)
#define AllocArrayResonance(n) (Resonance *) Calloc(n,ResonanceSize)
#define ResonancePntrSize sizeof(Resonance **)
#define AllocPntrArrayResonance(n) (Resonance **) Calloc(n,ResonancePntrSize)
#define SingCopyResonance(out,in) memcpy(out,in,ResonanceSize)
extern Resonance *CreateResonance(Resonance *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfAtoms,
                           INT *Atoms);

extern CHAR *GetNameResonance(Resonance *str);
extern INT  GetIDResonance(Resonance *str);
extern void PrintResonance(Resonance *eleptr);
extern void FreeResonance(Resonance *eleptr);
extern void *AllocResonance();
extern void WriteBinResonance(Resonance *eleptr, DbaseLinkedList *file);
extern INT ReadBinResonance(Resonance *eleptr, DbaseLinkedList *file);
extern void xdr_Resonance(XDR *stream, char **eleptr);
extern void CopyFullResonance(Resonance *newstruct, Resonance *oldstruct);
/*------------------------------------------*/
/*   Structures for Charge Routines   */
/* Structure:43:SetOfResonances

             NumberOfSets --(INT) Number Of Sets
                     Sets --(Resonance) The set of Resonant Sets
*/
typedef struct resonantsets SetOfResonances;
struct resonantsets {
     INT ID;
     CHAR *Name;
     INT  NumberOfSets;
     Resonance *Sets;
     };
#define SetOfResonancesSize sizeof(SetOfResonances)
#define AllocateSetOfResonances (SetOfResonances *) Malloc(SetOfResonancesSize)
#define AllocArraySetOfResonances(n) (SetOfResonances *) Calloc(n,SetOfResonancesSize)
#define SetOfResonancesPntrSize sizeof(SetOfResonances **)
#define AllocPntrArraySetOfResonances(n) (SetOfResonances **) Calloc(n,SetOfResonancesPntrSize)
#define SingCopySetOfResonances(out,in) memcpy(out,in,SetOfResonancesSize)
extern SetOfResonances *CreateSetOfResonances(SetOfResonances *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfSets,
                                       Resonance *Sets);

extern CHAR *GetNameSetOfResonances(SetOfResonances *str);
extern INT  GetIDSetOfResonances(SetOfResonances *str);
extern void PrintSetOfResonances(SetOfResonances *eleptr);
extern void FreeSetOfResonances(SetOfResonances *eleptr);
extern void *AllocSetOfResonances();
extern void WriteBinSetOfResonances(SetOfResonances *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfResonances(SetOfResonances *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfResonances(XDR *stream, char **eleptr);
extern void CopyFullSetOfResonances(SetOfResonances *newstruct, SetOfResonances *oldstruct);
/*------------------------------------------*/
/*   Structures for Charge Routines   */
/* Structure:31:MoleculeElectronic

                   NAtoms --(INT) The number of atoms in the molecule
                    Atoms --(AtomElectronic) AtomElectronic structures (vector of NAtom)
                BondOrder --(BondOrderMatrix) The bond order matrix
                 Resonant --(SetOfResonances) The set of Resonances
*/
typedef struct moleculeelectronic MoleculeElectronic;
struct moleculeelectronic {
     INT ID;
     CHAR *Name;
     INT  NAtoms;
     AtomElectronic *Atoms;
     BondOrderMatrix *BondOrder;
     SetOfResonances *Resonant;
     };
#define MoleculeElectronicSize sizeof(MoleculeElectronic)
#define AllocateMoleculeElectronic (MoleculeElectronic *) Malloc(MoleculeElectronicSize)
#define AllocArrayMoleculeElectronic(n) (MoleculeElectronic *) Calloc(n,MoleculeElectronicSize)
#define MoleculeElectronicPntrSize sizeof(MoleculeElectronic **)
#define AllocPntrArrayMoleculeElectronic(n) (MoleculeElectronic **) Calloc(n,MoleculeElectronicPntrSize)
#define SingCopyMoleculeElectronic(out,in) memcpy(out,in,MoleculeElectronicSize)
extern MoleculeElectronic *CreateMoleculeElectronic(MoleculeElectronic *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NAtoms,
                                             AtomElectronic *Atoms,
                                             BondOrderMatrix *BondOrder,
                                             SetOfResonances *Resonant);

extern CHAR *GetNameMoleculeElectronic(MoleculeElectronic *str);
extern INT  GetIDMoleculeElectronic(MoleculeElectronic *str);
extern void PrintMoleculeElectronic(MoleculeElectronic *eleptr);
extern void FreeMoleculeElectronic(MoleculeElectronic *eleptr);
extern void *AllocMoleculeElectronic();
extern void WriteBinMoleculeElectronic(MoleculeElectronic *eleptr, DbaseLinkedList *file);
extern INT ReadBinMoleculeElectronic(MoleculeElectronic *eleptr, DbaseLinkedList *file);
extern void xdr_MoleculeElectronic(XDR *stream, char **eleptr);
extern void CopyFullMoleculeElectronic(MoleculeElectronic *newstruct, MoleculeElectronic *oldstruct);
