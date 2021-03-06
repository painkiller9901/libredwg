#define DWG_TYPE DWG_TYPE_UNDERLAY
#include "common.c"

void
api_process (dwg_object *obj)
{
  int error;
  BITCODE_BL class_version;
  dwg_point_3d extrusion, insertion_pt, scale;
  BITCODE_RC flag;
  BITCODE_RC contrast;
  BITCODE_RC fade;
  BITCODE_BL num_clip_verts;
  dwg_point_2d* clip_verts;
  BITCODE_H underlay_layer;
  BITCODE_H definition_id;

  dwg_ent_underlay *underlay = dwg_object_to_UNDERLAY (obj);

  CHK_ENTITY_3RD (underlay, UNDERLAY, extrusion);
  CHK_ENTITY_3RD (underlay, UNDERLAY, insertion_pt);
  CHK_ENTITY_3RD (underlay, UNDERLAY, scale);
  CHK_ENTITY_TYPE (underlay, UNDERLAY, flag, RC);
  CHK_ENTITY_TYPE (underlay, UNDERLAY, contrast, RC);
  CHK_ENTITY_TYPE (underlay, UNDERLAY, fade, RC);
  CHK_ENTITY_TYPE (underlay, UNDERLAY, num_clip_verts, BL);

  if (!dwg_dynapi_entity_value (underlay, "UNDERLAY", "clip_verts", &clip_verts, NULL))
    fail ("UNDERLAY.clip_verts");
  else
    {
      for (BITCODE_BL i = 0; i < num_clip_verts; i++)
        {
          ok ("UNDERLAY.clip_verts[%d]: (%f, %f)", i, clip_verts[i].x, clip_verts[i].y);
        }
    }
  CHK_ENTITY_H (underlay, UNDERLAY, underlay_layer);
  CHK_ENTITY_H (underlay, UNDERLAY, definition_id);
}
