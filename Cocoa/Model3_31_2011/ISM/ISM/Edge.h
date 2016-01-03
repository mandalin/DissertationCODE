//
//  Edge.h
//  ISM
//
//  Created by Amanda Lind on 1/9/13.
//  Copyright (c) 2013 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_Edge_h
#define ISM_Edge_h

class Edge{
public:
    // Define Members
    int corner1ind;
	int corner2ind;
    int wall1ind;
    int wall2ind;
    bool right_handed; //NOTE: this handedness is from Wall1's perspective ! :)
    std::vector< wall*> walls_along_edge;
    position_vector edge_vector;
    position_vector edge_vector_normalized;
    
    
    static Edge * edgehead;
    Edge * previous;
    Edge * next;
    
    //Parametres for BTM
    double theta_w; //fluid angle
    //Parametres for UTD
    double alpha_w; //solid angle
    
    
	// Overload the default constructor.
	Edge()
    {
        //WE ASSUME THAT THE CORNERS LISTED IN SingleEdge are rotating around the normal using right hand rule !
        
        previous=NULL;
        next=NULL;
        walls_along_edge.clear();
        corner1ind=-1;
        corner2ind=-1;
        wall1ind=-1;
        wall2ind=-1;
        edge_vector.assign(NaN, NaN, NaN);
        edge_vector_normalized.assign(NaN, NaN, NaN);
        theta_w=NaN; //fluid angle
        alpha_w=NaN; //solid angle
        
	}
    
	
	// Constructor with parameters.
	Edge(int corn1, int corn2, int wall1, double solid_angle, std::vector<corner> & all_unique_corners, std::vector<wall> & planes)
	{
        previous=NULL;
        next=NULL;
        walls_along_edge.clear();
        corner1ind=NaN;
        corner1ind=-1;
        corner2ind=-1;
        wall1ind=-1;
        wall2ind=-1;
        edge_vector.assign(NaN, NaN, NaN);
        edge_vector_normalized.assign(NaN, NaN, NaN);
        theta_w=NaN; //fluid angle
        alpha_w=NaN; //solid angle
        
        
        wall1ind=wall1;
        if(wall1ind>=0)
        {   walls_along_edge.push_back(& planes[wall1ind]);
        }
        
        if(corn1 <= corn2)
        {
            corner1ind=corn1;
            corner2ind=corn2;
            right_handed=1;
        }
        else
        {
            corner1ind=corn2;
            corner2ind=corn1;
            right_handed=0;
        }
        
        
        
        edge_vector.assign( all_unique_corners[corner1ind].x - all_unique_corners[corner2ind].x , all_unique_corners[corner1ind].y - all_unique_corners[corner2ind].y, all_unique_corners[corner1ind].z - all_unique_corners[corner2ind].z);
        edge_vector_normalized.assign(edge_vector.x/magnitude(edge_vector), edge_vector.y/magnitude(edge_vector), edge_vector.z/magnitude(edge_vector));
        
        //Parametres for UTD
        alpha_w=solid_angle;                     //This is the solid angle of the edge
        //Parameters for BTM
        theta_w=(2.0*pi) - solid_angle;              //This is the fluid angle of the edge
        
    }
    
	// Constructor with fewer parameters.
    Edge(int corn1, int corn2, int wall1, std::vector<corner> & all_unique_corners, std::vector<wall> & planes)
	{
        previous=NULL;
        next=NULL;
        walls_along_edge.clear();
        corner1ind=-1;
        corner2ind=-1;
        wall1ind=-1;
        wall2ind=-1;
        edge_vector.assign(NaN, NaN, NaN);
        edge_vector_normalized.assign(NaN, NaN, NaN);
        theta_w=NaN; //fluid angle
        alpha_w=NaN; //solid angle
        
        
        wall1ind=wall1;
        if(wall1ind>=0)
        {   walls_along_edge.push_back(& planes[wall1ind]);
        }
        
        if(corn1 <= corn2)
        {
            corner1ind=corn1;
            corner2ind=corn2;
            right_handed=1;
        }
        else
        {
            corner1ind=corn2;
            corner2ind=corn1;
            right_handed=0;
        }
        
        
        
        edge_vector.assign( all_unique_corners[corner1ind].x - all_unique_corners[corner2ind].x , all_unique_corners[corner1ind].y - all_unique_corners[corner2ind].y, all_unique_corners[corner1ind].z - all_unique_corners[corner2ind].z);
        edge_vector_normalized.assign(edge_vector.x/magnitude(edge_vector), edge_vector.y/magnitude(edge_vector), edge_vector.z/magnitude(edge_vector));
        
    }
    
    
    void  assign(int corn1, int corn2, int wall1, double solid_angle, std::vector<corner> & all_unique_corners, std::vector<wall> & planes)
	{
        previous=NULL;
        next=NULL;
        walls_along_edge.clear();
        corner1ind=-1;
        corner2ind=-1;
        wall1ind=-1;
        wall2ind=-1;
        edge_vector.assign(NaN, NaN, NaN);
        edge_vector_normalized.assign(NaN, NaN, NaN);
        theta_w=NaN; //fluid angle
        alpha_w=NaN; //solid angle
        
        if(corn1 <= corn2)
        {
            corner1ind=corn1;
            corner2ind=corn2;
            right_handed=0;
        }
        else
        {
            corner1ind=corn2;
            corner2ind=corn1;
            right_handed=1;
        }
        
        wall1ind=wall1;
        if(wall1ind>=0)
        {   walls_along_edge.push_back(& planes[wall1ind]);
        }
        previous=NULL;
        next=NULL;
        
        
        edge_vector.assign( all_unique_corners[corner1ind].x - all_unique_corners[corner2ind].x , all_unique_corners[corner1ind].y - all_unique_corners[corner2ind].y, all_unique_corners[corner1ind].z - all_unique_corners[corner2ind].z);
        edge_vector_normalized.assign(edge_vector.x/magnitude(edge_vector), edge_vector.y/magnitude(edge_vector), edge_vector.z/magnitude(edge_vector));
        
    }
    
    
    void  assign(int corn1, int corn2, int wall1, std::vector<corner> & all_unique_corners, std::vector<wall> & planes)
	{
        previous=NULL;
        next=NULL;
        walls_along_edge.clear();
        corner1ind=-1;
        corner2ind=-1;
        wall1ind=-1;
        wall2ind=-1;
        edge_vector.assign(NaN, NaN, NaN);
        edge_vector_normalized.assign(NaN, NaN, NaN);
        theta_w=NaN; //fluid angle
        alpha_w=NaN; //solid angle
        
        if(corn1 <= corn2)
        {
            corner1ind=corn1;
            corner2ind=corn2;
            right_handed=1;
        }
        else
        {
            corner1ind=corn2;
            corner2ind=corn1;
            right_handed=0;
        }
        
        wall1ind=wall1;
        if(wall1ind>=0)
        {   walls_along_edge.push_back(& planes[wall1ind]);
        }
        previous=NULL;
        next=NULL;
        
        
        edge_vector.assign( all_unique_corners[corner1ind].x - all_unique_corners[corner2ind].x , all_unique_corners[corner1ind].y - all_unique_corners[corner2ind].y, all_unique_corners[corner1ind].z - all_unique_corners[corner2ind].z);
        edge_vector_normalized.assign(edge_vector.x/magnitude(edge_vector), edge_vector.y/magnitude(edge_vector), edge_vector.z/magnitude(edge_vector));
        
    }
    
    
    
    //Things that should happen before this function is called...
    // 1. Create New Edge Object on the Stack
    //Edge * Edge2Add = new Edge();
    // 2. Assign it some values
    //Edge2Add->assign(corn1, corn2,all_unique_corners);
    
    void Calculate_Solid_Angle()
    {
        double costheta, theta; //this is the accute angle between the planes
        
        position_vector test1(walls_along_edge[0]->normal),test2(walls_along_edge[1]->normal);
        
        costheta=dot(test1,test2);
        
        theta=std::acos(costheta);
        
        position_vector vector_along_wall1, reversed_edge_vector_normalized;
        
        if(right_handed)
        {   vector_along_wall1=cross(walls_along_edge[0]->normal , edge_vector_normalized);
            //this vector is in the plane and points away from the corner
        }
        else
        {
            reversed_edge_vector_normalized=mult(edge_vector_normalized,-1);
            vector_along_wall1=cross(walls_along_edge[0]->normal , reversed_edge_vector_normalized);
            //this vector is in the plane and points away from the corner
        }
        
        position_vector onepoint;
        onepoint=add( onepoint, walls_along_edge[0]->unique_corners[corner1ind] );
        bool point_in_front;
        double solid_angle;
        
        point_in_front = IsInfront(onepoint, walls_along_edge[1]->normal, walls_along_edge[0]->unique_corners[corner1ind],  .0000001);
        //bool IsInfront(position_vector onepoint, position_vector norm, position_vector onecorner,  double buffer)
        
        if(point_in_front)
        {
            solid_angle=pi+theta;
        }
        else
        {
            solid_angle=pi-theta;
        }
        
        alpha_w=solid_angle; //solid angle
        theta_w=2*pi-solid_angle; //fluid angle
        
        
        return;
        
    }
    
     Edge *  AddEdge(std::vector<corner> all_unique_corners, Edge * EdgeHead, Edge * Edge2Add, std::vector<wall> & planes)
    {
        
        //create a pointer that will go out of scope, with no object, with which to explore the linked list
        Edge * current_edge;
        current_edge=EdgeHead;
        
        //If there is no edge in the list, the edge being added becomes the head of the list and we exit the function
        if(EdgeHead==NULL)
        {
            EdgeHead=Edge2Add;
          //  edgehead=EdgeHead;
            return EdgeHead;
        }
        
        //If there are in fact edges in the list, this porting goes through them, and finds the place where the new edge should be added, based on the sequece of the indices
        bool at_end_of_list=false;
        while(!at_end_of_list)
        {
            
                
            //move the current edge to the next edge, if this edge belongs after
            if(Edge2Add->corner1ind > current_edge->corner1ind)
            {   if(current_edge->next == NULL)
                {   at_end_of_list=true;
                    current_edge->next=Edge2Add;
                    Edge2Add->previous=current_edge;
                    return EdgeHead;
                }
                else
                {       current_edge=current_edge->next;
                }
            }
            
            else if(Edge2Add->corner1ind == current_edge->corner1ind)
            {
                //move the current edge to the next edge, if this edge belongs after
                if(Edge2Add->corner2ind > current_edge->corner2ind)
                {
                    if(current_edge->next == NULL)
                    {   at_end_of_list=true;
                        current_edge->next=Edge2Add;
                        Edge2Add->previous=current_edge;
                        return EdgeHead;
                    }
                    else
                    {       current_edge=current_edge->next;
                    }
                
                
                
                }
                
                //this case occurs if the added edge and the current edge are the same edge
                else if(Edge2Add->corner2ind == current_edge->corner2ind)
                {   if(current_edge->wall2ind == -1)
                        {   current_edge->wall2ind=Edge2Add->wall1ind;
                            current_edge->walls_along_edge.push_back(& planes[current_edge->wall2ind]);
                            return EdgeHead;
                        }
                    else
                        {   perror ( "This Edge is Duplicated");
                            return EdgeHead;
                        }
                
                }
                
                //this case occurs if the added belongs before the current edge and is shuffled into place
                else
                {   if(current_edge==EdgeHead)
                    {   Edge2Add->next=current_edge;
                        current_edge->previous=Edge2Add;
                        EdgeHead=Edge2Add;
                        return EdgeHead;
                    }
                    Edge2Add->next=current_edge;
                    current_edge=current_edge->previous;
                    Edge2Add->previous=current_edge;
                    current_edge->next=Edge2Add;
                    current_edge=Edge2Add->next;
                    current_edge->previous=Edge2Add;
                    return EdgeHead;
                }
            }
            
            //this case occurs if the added belongs before the current edge and is shuffled into place
            else
            {   if(current_edge==EdgeHead)
                {   Edge2Add->next=current_edge;
                    current_edge->previous=Edge2Add;
                    EdgeHead=Edge2Add;
                    return EdgeHead;
                }
                else
                {   Edge2Add->next=current_edge;
                    current_edge=current_edge->previous;
                    Edge2Add->previous=current_edge;
                    current_edge->next=Edge2Add;
                    current_edge=Edge2Add->next;
                    current_edge->previous=Edge2Add;
                    return EdgeHead;
                }
            }
            
        }
        
        
    }
    
};
#endif