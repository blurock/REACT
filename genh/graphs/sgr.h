/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:Neighbor

        NumberOfNeighbors --(INT) Number Of Neighbors
                     List --(INT) The list of Neighbor ID's
*/
typedef struct neighbors Neighbor;
struct neighbors {
     INT ID;
     CHAR *Name;
     INT  NumberOfNeighbors;
     INT *List;
     };
#define NeighborSize sizeof(Neighbor)
#define AllocateNeighbor (Neighbor *) Malloc(NeighborSize)
#define AllocArrayNeighbor(n) (Neighbor *) Calloc(n,NeighborSize)
#define NeighborPntrSize sizeof(Neighbor **)
#define AllocPntrArrayNeighbor(n) (Neighbor **) Calloc(n,NeighborPntrSize)
#define SingCopyNeighbor(out,in) memcpy(out,in,NeighborSize)
extern Neighbor *CreateNeighbor(Neighbor *newstruct,
                         INT id,
                         CHAR *name,
                         INT  NumberOfNeighbors,
                         INT *List);

extern CHAR *GetNameNeighbor(Neighbor *str);
extern INT  GetIDNeighbor(Neighbor *str);
extern void PrintNeighbor(Neighbor *eleptr);
extern void FreeNeighbor(Neighbor *eleptr);
extern void *AllocNeighbor();
extern void WriteBinNeighbor(Neighbor *eleptr, DbaseLinkedList *file);
extern INT ReadBinNeighbor(Neighbor *eleptr, DbaseLinkedList *file);
extern void xdr_Neighbor(XDR *stream, char **eleptr);
extern void CopyFullNeighbor(Neighbor *newstruct, Neighbor *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:GraphMetaAtom

          NumberOfAliased --(INT) The Number of Possibilities
              AtomicTypes --(INT) The Atomic Types
*/
typedef struct graphmetaatom GraphMetaAtom;
struct graphmetaatom {
     INT ID;
     CHAR *Name;
     INT  NumberOfAliased;
     INT *AtomicTypes;
     };
#define GraphMetaAtomSize sizeof(GraphMetaAtom)
#define AllocateGraphMetaAtom (GraphMetaAtom *) Malloc(GraphMetaAtomSize)
#define AllocArrayGraphMetaAtom(n) (GraphMetaAtom *) Calloc(n,GraphMetaAtomSize)
#define GraphMetaAtomPntrSize sizeof(GraphMetaAtom **)
#define AllocPntrArrayGraphMetaAtom(n) (GraphMetaAtom **) Calloc(n,GraphMetaAtomPntrSize)
#define SingCopyGraphMetaAtom(out,in) memcpy(out,in,GraphMetaAtomSize)
extern GraphMetaAtom *CreateGraphMetaAtom(GraphMetaAtom *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfAliased,
                                   INT *AtomicTypes);

extern CHAR *GetNameGraphMetaAtom(GraphMetaAtom *str);
extern INT  GetIDGraphMetaAtom(GraphMetaAtom *str);
extern void PrintGraphMetaAtom(GraphMetaAtom *eleptr);
extern void FreeGraphMetaAtom(GraphMetaAtom *eleptr);
extern void *AllocGraphMetaAtom();
extern void WriteBinGraphMetaAtom(GraphMetaAtom *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphMetaAtom(GraphMetaAtom *eleptr, DbaseLinkedList *file);
extern void xdr_GraphMetaAtom(XDR *stream, char **eleptr);
extern void CopyFullGraphMetaAtom(GraphMetaAtom *newstruct, GraphMetaAtom *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:15:SetOfGraphMetaAtoms

        NumberOfMetaAtoms --(INT) The number of MetaAtoms
                MetaAtoms --(GraphMetaAtom) The Set of MetaAtoms
*/
typedef struct setofgraphmetaatoms SetOfGraphMetaAtoms;
struct setofgraphmetaatoms {
     INT ID;
     CHAR *Name;
     INT  NumberOfMetaAtoms;
     GraphMetaAtom *MetaAtoms;
     };
#define SetOfGraphMetaAtomsSize sizeof(SetOfGraphMetaAtoms)
#define AllocateSetOfGraphMetaAtoms (SetOfGraphMetaAtoms *) Malloc(SetOfGraphMetaAtomsSize)
#define AllocArraySetOfGraphMetaAtoms(n) (SetOfGraphMetaAtoms *) Calloc(n,SetOfGraphMetaAtomsSize)
#define SetOfGraphMetaAtomsPntrSize sizeof(SetOfGraphMetaAtoms **)
#define AllocPntrArraySetOfGraphMetaAtoms(n) (SetOfGraphMetaAtoms **) Calloc(n,SetOfGraphMetaAtomsPntrSize)
#define SingCopySetOfGraphMetaAtoms(out,in) memcpy(out,in,SetOfGraphMetaAtomsSize)
extern SetOfGraphMetaAtoms *CreateSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfMetaAtoms,
                                               GraphMetaAtom *MetaAtoms);

extern CHAR *GetNameSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *str);
extern INT  GetIDSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *str);
extern void PrintSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr);
extern void FreeSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr);
extern void *AllocSetOfGraphMetaAtoms();
extern void WriteBinSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfGraphMetaAtoms(XDR *stream, char **eleptr);
extern void CopyFullSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *newstruct, SetOfGraphMetaAtoms *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:51:Graph

            NumberOfNodes --(INT) Number of Nodes in Graph
                NodeTypes --(INT) Types (Colors) of the Nodes
                Neighbors --(Neighbor) The set of Neighbors
                MetaAtoms --(SetOfGraphMetaAtoms) The set of MetaAtoms
*/
typedef struct graph Graph;
struct graph {
     INT ID;
     CHAR *Name;
     INT  NumberOfNodes;
     INT *NodeTypes;
     Neighbor *Neighbors;
     SetOfGraphMetaAtoms *MetaAtoms;
     };
#define GraphSize sizeof(Graph)
#define AllocateGraph (Graph *) Malloc(GraphSize)
#define AllocArrayGraph(n) (Graph *) Calloc(n,GraphSize)
#define GraphPntrSize sizeof(Graph **)
#define AllocPntrArrayGraph(n) (Graph **) Calloc(n,GraphPntrSize)
#define SingCopyGraph(out,in) memcpy(out,in,GraphSize)
extern Graph *CreateGraph(Graph *newstruct,
                   INT id,
                   CHAR *name,
                   INT  NumberOfNodes,
                   INT *NodeTypes,
                   Neighbor *Neighbors,
                   SetOfGraphMetaAtoms *MetaAtoms);

extern CHAR *GetNameGraph(Graph *str);
extern INT  GetIDGraph(Graph *str);
extern void PrintGraph(Graph *eleptr);
extern void FreeGraph(Graph *eleptr);
extern void *AllocGraph();
extern void WriteBinGraph(Graph *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraph(Graph *eleptr, DbaseLinkedList *file);
extern void xdr_Graph(XDR *stream, char **eleptr);
extern void CopyFullGraph(Graph *newstruct, Graph *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:SetOfGraphs

           NumberOfGraphs --(INT) The number of graphs
                   Graphs --(Graph) The set of graphs
*/
typedef struct setofgraphs SetOfGraphs;
struct setofgraphs {
     INT ID;
     CHAR *Name;
     INT  NumberOfGraphs;
     Graph *Graphs;
     };
#define SetOfGraphsSize sizeof(SetOfGraphs)
#define AllocateSetOfGraphs (SetOfGraphs *) Malloc(SetOfGraphsSize)
#define AllocArraySetOfGraphs(n) (SetOfGraphs *) Calloc(n,SetOfGraphsSize)
#define SetOfGraphsPntrSize sizeof(SetOfGraphs **)
#define AllocPntrArraySetOfGraphs(n) (SetOfGraphs **) Calloc(n,SetOfGraphsPntrSize)
#define SingCopySetOfGraphs(out,in) memcpy(out,in,SetOfGraphsSize)
extern SetOfGraphs *CreateSetOfGraphs(SetOfGraphs *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfGraphs,
                               Graph *Graphs);

extern CHAR *GetNameSetOfGraphs(SetOfGraphs *str);
extern INT  GetIDSetOfGraphs(SetOfGraphs *str);
extern void PrintSetOfGraphs(SetOfGraphs *eleptr);
extern void FreeSetOfGraphs(SetOfGraphs *eleptr);
extern void *AllocSetOfGraphs();
extern void WriteBinSetOfGraphs(SetOfGraphs *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfGraphs(SetOfGraphs *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfGraphs(XDR *stream, char **eleptr);
extern void CopyFullSetOfGraphs(SetOfGraphs *newstruct, SetOfGraphs *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:GraphReaction

                NumberLHS --(INT) The number of graphs on left hand side
                 GraphLHS --(Graph) The set of graph on the left hand side
                NumberRHS --(INT) The number of graphs on the right hand side
                 GraphRHS --(Graph) The set of graphs on the RHS
*/
typedef struct graphreaction GraphReaction;
struct graphreaction {
     INT ID;
     CHAR *Name;
     INT  NumberLHS;
     Graph *GraphLHS;
     INT  NumberRHS;
     Graph *GraphRHS;
     };
#define GraphReactionSize sizeof(GraphReaction)
#define AllocateGraphReaction (GraphReaction *) Malloc(GraphReactionSize)
#define AllocArrayGraphReaction(n) (GraphReaction *) Calloc(n,GraphReactionSize)
#define GraphReactionPntrSize sizeof(GraphReaction **)
#define AllocPntrArrayGraphReaction(n) (GraphReaction **) Calloc(n,GraphReactionPntrSize)
#define SingCopyGraphReaction(out,in) memcpy(out,in,GraphReactionSize)
extern GraphReaction *CreateGraphReaction(GraphReaction *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberLHS,
                                   Graph *GraphLHS,
                                   INT  NumberRHS,
                                   Graph *GraphRHS);

extern CHAR *GetNameGraphReaction(GraphReaction *str);
extern INT  GetIDGraphReaction(GraphReaction *str);
extern void PrintGraphReaction(GraphReaction *eleptr);
extern void FreeGraphReaction(GraphReaction *eleptr);
extern void *AllocGraphReaction();
extern void WriteBinGraphReaction(GraphReaction *eleptr, DbaseLinkedList *file);
extern INT ReadBinGraphReaction(GraphReaction *eleptr, DbaseLinkedList *file);
extern void xdr_GraphReaction(XDR *stream, char **eleptr);
extern void CopyFullGraphReaction(GraphReaction *newstruct, GraphReaction *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:SetOfGraphReactions

     NumberOfGraphReactions --(INT) The number of graph reactions
                Reactions --(GraphReaction) The set of graph reactions
*/
typedef struct setofgraphreactions SetOfGraphReactions;
struct setofgraphreactions {
     INT ID;
     CHAR *Name;
     INT  NumberOfGraphReactions;
     GraphReaction *Reactions;
     };
#define SetOfGraphReactionsSize sizeof(SetOfGraphReactions)
#define AllocateSetOfGraphReactions (SetOfGraphReactions *) Malloc(SetOfGraphReactionsSize)
#define AllocArraySetOfGraphReactions(n) (SetOfGraphReactions *) Calloc(n,SetOfGraphReactionsSize)
#define SetOfGraphReactionsPntrSize sizeof(SetOfGraphReactions **)
#define AllocPntrArraySetOfGraphReactions(n) (SetOfGraphReactions **) Calloc(n,SetOfGraphReactionsPntrSize)
#define SingCopySetOfGraphReactions(out,in) memcpy(out,in,SetOfGraphReactionsSize)
extern SetOfGraphReactions *CreateSetOfGraphReactions(SetOfGraphReactions *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfGraphReactions,
                                               GraphReaction *Reactions);

extern CHAR *GetNameSetOfGraphReactions(SetOfGraphReactions *str);
extern INT  GetIDSetOfGraphReactions(SetOfGraphReactions *str);
extern void PrintSetOfGraphReactions(SetOfGraphReactions *eleptr);
extern void FreeSetOfGraphReactions(SetOfGraphReactions *eleptr);
extern void *AllocSetOfGraphReactions();
extern void WriteBinSetOfGraphReactions(SetOfGraphReactions *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfGraphReactions(SetOfGraphReactions *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfGraphReactions(XDR *stream, char **eleptr);
extern void CopyFullSetOfGraphReactions(SetOfGraphReactions *newstruct, SetOfGraphReactions *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:55:CombinedGraph

                 Combined --(Graph) The combined graph
           NumberOfBegins --(INT) The number of graphs in the one graph
                   Begins --(INT) The set of Begin Points of the nodes of the corr. graphs
*/
typedef struct graphbegins CombinedGraph;
struct graphbegins {
     INT ID;
     CHAR *Name;
     Graph *Combined;
     INT  NumberOfBegins;
     INT *Begins;
     };
#define CombinedGraphSize sizeof(CombinedGraph)
#define AllocateCombinedGraph (CombinedGraph *) Malloc(CombinedGraphSize)
#define AllocArrayCombinedGraph(n) (CombinedGraph *) Calloc(n,CombinedGraphSize)
#define CombinedGraphPntrSize sizeof(CombinedGraph **)
#define AllocPntrArrayCombinedGraph(n) (CombinedGraph **) Calloc(n,CombinedGraphPntrSize)
#define SingCopyCombinedGraph(out,in) memcpy(out,in,CombinedGraphSize)
extern CombinedGraph *CreateCombinedGraph(CombinedGraph *newstruct,
                                   INT id,
                                   CHAR *name,
                                   Graph *Combined,
                                   INT  NumberOfBegins,
                                   INT *Begins);

extern CHAR *GetNameCombinedGraph(CombinedGraph *str);
extern INT  GetIDCombinedGraph(CombinedGraph *str);
extern void PrintCombinedGraph(CombinedGraph *eleptr);
extern void FreeCombinedGraph(CombinedGraph *eleptr);
extern void *AllocCombinedGraph();
extern void WriteBinCombinedGraph(CombinedGraph *eleptr, DbaseLinkedList *file);
extern INT ReadBinCombinedGraph(CombinedGraph *eleptr, DbaseLinkedList *file);
extern void xdr_CombinedGraph(XDR *stream, char **eleptr);
extern void CopyFullCombinedGraph(CombinedGraph *newstruct, CombinedGraph *oldstruct);
/*------------------------------------------*/
/*   Structures For Graphs   */
/* Structure:52:SetOfCombinedGraphs

          NumberOfCGraphs --(INT) The number of graphs
                  CGraphs --(CombinedGraph) The set of graphs
*/
typedef struct setofcombinedgraphs SetOfCombinedGraphs;
struct setofcombinedgraphs {
     INT ID;
     CHAR *Name;
     INT  NumberOfCGraphs;
     CombinedGraph *CGraphs;
     };
#define SetOfCombinedGraphsSize sizeof(SetOfCombinedGraphs)
#define AllocateSetOfCombinedGraphs (SetOfCombinedGraphs *) Malloc(SetOfCombinedGraphsSize)
#define AllocArraySetOfCombinedGraphs(n) (SetOfCombinedGraphs *) Calloc(n,SetOfCombinedGraphsSize)
#define SetOfCombinedGraphsPntrSize sizeof(SetOfCombinedGraphs **)
#define AllocPntrArraySetOfCombinedGraphs(n) (SetOfCombinedGraphs **) Calloc(n,SetOfCombinedGraphsPntrSize)
#define SingCopySetOfCombinedGraphs(out,in) memcpy(out,in,SetOfCombinedGraphsSize)
extern SetOfCombinedGraphs *CreateSetOfCombinedGraphs(SetOfCombinedGraphs *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfCGraphs,
                                               CombinedGraph *CGraphs);

extern CHAR *GetNameSetOfCombinedGraphs(SetOfCombinedGraphs *str);
extern INT  GetIDSetOfCombinedGraphs(SetOfCombinedGraphs *str);
extern void PrintSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr);
extern void FreeSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr);
extern void *AllocSetOfCombinedGraphs();
extern void WriteBinSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfCombinedGraphs(XDR *stream, char **eleptr);
extern void CopyFullSetOfCombinedGraphs(SetOfCombinedGraphs *newstruct, SetOfCombinedGraphs *oldstruct);
