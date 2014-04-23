/*------------------------------------------*/
/*   Structures for the CHEMKIN Thermo data   */
/* Structure:100:ThermoCoefficients

     NumberOfCoefficients --(INT) The number of coefficients
             Coefficients --(FLOAT) The set of coefficients
*/
typedef struct thermocoefficients ThermoCoefficients;
struct thermocoefficients {
     INT ID;
     CHAR *Name;
     INT  NumberOfCoefficients;
     FLOAT *Coefficients;
     };
#define ThermoCoefficientsSize sizeof(ThermoCoefficients)
#define AllocateThermoCoefficients (ThermoCoefficients *) Malloc(ThermoCoefficientsSize)
#define AllocArrayThermoCoefficients(n) (ThermoCoefficients *) Calloc(n,ThermoCoefficientsSize)
#define ThermoCoefficientsPntrSize sizeof(ThermoCoefficients **)
#define AllocPntrArrayThermoCoefficients(n) (ThermoCoefficients **) Calloc(n,ThermoCoefficientsPntrSize)
#define SingCopyThermoCoefficients(out,in) memcpy(out,in,ThermoCoefficientsSize)
extern ThermoCoefficients *CreateThermoCoefficients(ThermoCoefficients *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfCoefficients,
                                             FLOAT *Coefficients);

extern CHAR *GetNameThermoCoefficients(ThermoCoefficients *str);
extern INT  GetIDThermoCoefficients(ThermoCoefficients *str);
extern void PrintThermoCoefficients(ThermoCoefficients *eleptr);
extern void FreeThermoCoefficients(ThermoCoefficients *eleptr);
extern void *AllocThermoCoefficients();
extern void WriteBinThermoCoefficients(ThermoCoefficients *eleptr, DbaseLinkedList *file);
extern INT ReadBinThermoCoefficients(ThermoCoefficients *eleptr, DbaseLinkedList *file);
extern void xdr_ThermoCoefficients(XDR *stream, char **eleptr);
extern void CopyFullThermoCoefficients(ThermoCoefficients *newstruct, ThermoCoefficients *oldstruct);
/*------------------------------------------*/
/*   Structures for the CHEMKIN Thermo data   */
/* Structure:101:ChemkinAtomicInfo

             AtomicNumber --(INT) The Atomic Number
                  Formula --(INT) The Number of this atom in the molecule
*/
typedef struct chemkinatomicinfo ChemkinAtomicInfo;
struct chemkinatomicinfo {
     INT ID;
     CHAR *Name;
     INT  AtomicNumber;
     INT  Formula;
     };
#define ChemkinAtomicInfoSize sizeof(ChemkinAtomicInfo)
#define AllocateChemkinAtomicInfo (ChemkinAtomicInfo *) Malloc(ChemkinAtomicInfoSize)
#define AllocArrayChemkinAtomicInfo(n) (ChemkinAtomicInfo *) Calloc(n,ChemkinAtomicInfoSize)
#define ChemkinAtomicInfoPntrSize sizeof(ChemkinAtomicInfo **)
#define AllocPntrArrayChemkinAtomicInfo(n) (ChemkinAtomicInfo **) Calloc(n,ChemkinAtomicInfoPntrSize)
#define SingCopyChemkinAtomicInfo(out,in) memcpy(out,in,ChemkinAtomicInfoSize)
extern ChemkinAtomicInfo *CreateChemkinAtomicInfo(ChemkinAtomicInfo *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  AtomicNumber,
                                           INT  Formula);

extern CHAR *GetNameChemkinAtomicInfo(ChemkinAtomicInfo *str);
extern INT  GetIDChemkinAtomicInfo(ChemkinAtomicInfo *str);
extern void PrintChemkinAtomicInfo(ChemkinAtomicInfo *eleptr);
extern void FreeChemkinAtomicInfo(ChemkinAtomicInfo *eleptr);
extern void *AllocChemkinAtomicInfo();
extern void WriteBinChemkinAtomicInfo(ChemkinAtomicInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinChemkinAtomicInfo(ChemkinAtomicInfo *eleptr, DbaseLinkedList *file);
extern void xdr_ChemkinAtomicInfo(XDR *stream, char **eleptr);
extern void CopyFullChemkinAtomicInfo(ChemkinAtomicInfo *newstruct, ChemkinAtomicInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for the CHEMKIN Thermo data   */
/* Structure:102:SetOfChemkinAtomicInfo

            NumberOfAtoms --(INT) The number of atoms
                    Atoms --(ChemkinAtomicInfo) The atoms 
*/
typedef struct setofchemkinatomicinfo SetOfChemkinAtomicInfo;
struct setofchemkinatomicinfo {
     INT ID;
     CHAR *Name;
     INT  NumberOfAtoms;
     ChemkinAtomicInfo *Atoms;
     };
#define SetOfChemkinAtomicInfoSize sizeof(SetOfChemkinAtomicInfo)
#define AllocateSetOfChemkinAtomicInfo (SetOfChemkinAtomicInfo *) Malloc(SetOfChemkinAtomicInfoSize)
#define AllocArraySetOfChemkinAtomicInfo(n) (SetOfChemkinAtomicInfo *) Calloc(n,SetOfChemkinAtomicInfoSize)
#define SetOfChemkinAtomicInfoPntrSize sizeof(SetOfChemkinAtomicInfo **)
#define AllocPntrArraySetOfChemkinAtomicInfo(n) (SetOfChemkinAtomicInfo **) Calloc(n,SetOfChemkinAtomicInfoPntrSize)
#define SingCopySetOfChemkinAtomicInfo(out,in) memcpy(out,in,SetOfChemkinAtomicInfoSize)
extern SetOfChemkinAtomicInfo *CreateSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *newstruct,
                                                     INT id,
                                                     CHAR *name,
                                                     INT  NumberOfAtoms,
                                                     ChemkinAtomicInfo *Atoms);

extern CHAR *GetNameSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *str);
extern INT  GetIDSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *str);
extern void PrintSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr);
extern void FreeSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr);
extern void *AllocSetOfChemkinAtomicInfo();
extern void WriteBinSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfChemkinAtomicInfo(XDR *stream, char **eleptr);
extern void CopyFullSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *newstruct, SetOfChemkinAtomicInfo *oldstruct);
/*------------------------------------------*/
/*   Structures for the CHEMKIN Thermo data   */
/* Structure:101:ChemkinThermoRead

                  Species --(STRING) Species Name
                AtomicSet --(SetOfChemkinAtomicInfo) The set of atoms
                    Phase --(INT) The Phase of the molecule information
           LowTemperature --(FLOAT) The Low Temperature
          HighTemperature --(FLOAT) The High Temperature
        CommonTemperature --(FLOAT) The command Temperature
     UpperTempCoefficients --(ThermoCoefficients) The coefficients for the upper temperature
     LowerTempCoefficients --(ThermoCoefficients) The coefficients for the lower temperature
*/
typedef struct chemkinthermoread ChemkinThermoRead;
struct chemkinthermoread {
     INT ID;
     CHAR *Name;
     STRING *Species;
     SetOfChemkinAtomicInfo *AtomicSet;
     INT  Phase;
     FLOAT  LowTemperature;
     FLOAT  HighTemperature;
     FLOAT  CommonTemperature;
     ThermoCoefficients *UpperTempCoefficients;
     ThermoCoefficients *LowerTempCoefficients;
     };
#define ChemkinThermoReadSize sizeof(ChemkinThermoRead)
#define AllocateChemkinThermoRead (ChemkinThermoRead *) Malloc(ChemkinThermoReadSize)
#define AllocArrayChemkinThermoRead(n) (ChemkinThermoRead *) Calloc(n,ChemkinThermoReadSize)
#define ChemkinThermoReadPntrSize sizeof(ChemkinThermoRead **)
#define AllocPntrArrayChemkinThermoRead(n) (ChemkinThermoRead **) Calloc(n,ChemkinThermoReadPntrSize)
#define SingCopyChemkinThermoRead(out,in) memcpy(out,in,ChemkinThermoReadSize)
extern ChemkinThermoRead *CreateChemkinThermoRead(ChemkinThermoRead *newstruct,
                                           INT id,
                                           CHAR *name,
                                           SetOfChemkinAtomicInfo *AtomicSet,
                                           INT  Phase,
                                           FLOAT  LowTemperature,
                                           FLOAT  HighTemperature,
                                           FLOAT  CommonTemperature,
                                           ThermoCoefficients *UpperTempCoefficients,
                                           ThermoCoefficients *LowerTempCoefficients);

extern CHAR *GetNameChemkinThermoRead(ChemkinThermoRead *str);
extern INT  GetIDChemkinThermoRead(ChemkinThermoRead *str);
extern void PrintChemkinThermoRead(ChemkinThermoRead *eleptr);
extern void FreeChemkinThermoRead(ChemkinThermoRead *eleptr);
extern void *AllocChemkinThermoRead();
extern void WriteBinChemkinThermoRead(ChemkinThermoRead *eleptr, DbaseLinkedList *file);
extern INT ReadBinChemkinThermoRead(ChemkinThermoRead *eleptr, DbaseLinkedList *file);
extern void xdr_ChemkinThermoRead(XDR *stream, char **eleptr);
extern void CopyFullChemkinThermoRead(ChemkinThermoRead *newstruct, ChemkinThermoRead *oldstruct);
/*------------------------------------------*/
/*   Structures for the CHEMKIN Thermo data   */
/* Structure:105:SetOfChemkinThermoInformation

        NumberOfMolecules --(INT) The number of atoms read in
                   Thermo --(ChemkinThermoRead) The set of thermodynamic information
*/
typedef struct setofchemkinthermoinformation SetOfChemkinThermoInformation;
struct setofchemkinthermoinformation {
     INT ID;
     CHAR *Name;
     INT  NumberOfMolecules;
     ChemkinThermoRead *Thermo;
     };
#define SetOfChemkinThermoInformationSize sizeof(SetOfChemkinThermoInformation)
#define AllocateSetOfChemkinThermoInformation (SetOfChemkinThermoInformation *) Malloc(SetOfChemkinThermoInformationSize)
#define AllocArraySetOfChemkinThermoInformation(n) (SetOfChemkinThermoInformation *) Calloc(n,SetOfChemkinThermoInformationSize)
#define SetOfChemkinThermoInformationPntrSize sizeof(SetOfChemkinThermoInformation **)
#define AllocPntrArraySetOfChemkinThermoInformation(n) (SetOfChemkinThermoInformation **) Calloc(n,SetOfChemkinThermoInformationPntrSize)
#define SingCopySetOfChemkinThermoInformation(out,in) memcpy(out,in,SetOfChemkinThermoInformationSize)
extern SetOfChemkinThermoInformation *CreateSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *newstruct,
INT id,
CHAR *name,
INT  NumberOfMolecules,
ChemkinThermoRead *Thermo);

extern CHAR *GetNameSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *str);
extern INT  GetIDSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *str);
extern void PrintSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr);
extern void FreeSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr);
extern void *AllocSetOfChemkinThermoInformation();
extern void WriteBinSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfChemkinThermoInformation(XDR *stream, char **eleptr);
extern void CopyFullSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *newstruct, SetOfChemkinThermoInformation *oldstruct);
