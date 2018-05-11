/*-------------------------------------------------------------------------
 *
 * plancat.h
 *	  prototypes for plancat.c.
 *
 *
 * Portions Copyright (c) 1996-2018, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/optimizer/plancat.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef PLANCAT_H
#define PLANCAT_H

#include "nodes/relation.h"
#include "utils/relcache.h"

/* Hook for plugins to get control in get_relation_info() */
typedef void (*get_relation_info_hook_type) (PlannerInfo *root,
											 Oid relationObjectId,
											 bool inhparent,
											 RelOptInfo *rel);
extern PGDLLIMPORT get_relation_info_hook_type get_relation_info_hook;
/* Hook for plugings to simulate partitioning*/
typedef PartitionDesc (*RelationGetPartitionDesc_hook_type) (RelOptInfo *rel);
extern PGDLLIMPORT RelationGetPartitionDesc_hook_type RelationGetPartitionDesc_hook;
typedef PartitionKey (*RelationGetPartitionKey_hook_type) (RelOptInfo *rel);
extern PGDLLIMPORT RelationGetPartitionKey_hook_type RelationGetPartitionKey_hook;
typedef List *(*generate_partition_qual_hook_type) (RelOptInfo *rel);
extern PGDLLIMPORT generate_partition_qual_hook_type generate_partition_qual_hook;


extern void get_relation_info(PlannerInfo *root, Oid relationObjectId,
				  bool inhparent, RelOptInfo *rel);

extern List *infer_arbiter_indexes(PlannerInfo *root);

extern void estimate_rel_size(Relation rel, int32 *attr_widths,
				  BlockNumber *pages, double *tuples, double *allvisfrac);

extern int32 get_relation_data_width(Oid relid, int32 *attr_widths);

extern bool relation_excluded_by_constraints(PlannerInfo *root,
								 RelOptInfo *rel, RangeTblEntry *rte);

extern List *build_physical_tlist(PlannerInfo *root, RelOptInfo *rel);

extern bool has_unique_index(RelOptInfo *rel, AttrNumber attno);

extern Selectivity restriction_selectivity(PlannerInfo *root,
						Oid operatorid,
						List *args,
						Oid inputcollid,
						int varRelid);

extern Selectivity join_selectivity(PlannerInfo *root,
				 Oid operatorid,
				 List *args,
				 Oid inputcollid,
				 JoinType jointype,
				 SpecialJoinInfo *sjinfo);

extern bool has_row_triggers(PlannerInfo *root, Index rti, CmdType event);

#endif							/* PLANCAT_H */
