#include "TraitementSegment.h"
#include "Segment.h"

TraitementSegment::TraitementSegment(TraitementForme *suivant):TraitementForme(suivant) {}

FormeGeometrique* TraitementSegment::traiter1(const char *instruction) const {
	string couleur;
	double x1, x2, y1, y2;
	if (sscanf_s(instruction, "Segment (%s,%lf,%lf,%lf,%lf);", &couleur, &x1, &y1, &x2, &y2) != 0) {
		return new Segment(couleur, x1, y1, x2, y2);
	}else if (sscanf_s(instruction, "Segment (%lf,%lf,%lf,%lf);", &x1, &y1, &x2, &y2) != 0) {
		return new Segment(x1, y1, x2, y2);
	}
	else
		return NULL;
}