//
//  ReadInSourceFile.h
//  ISM
//
//  Created by Amanda Lind on 6/28/12.
//  Copyright (c) 2012 Pennsylvania State University. All rights reserved.
//

#ifndef ISM_ReadInSourceFile_h
#define ISM_ReadInSourceFile_h

std::vector<source> ReadInSourceFile(char * Directory,  const char * filename , double & az, double & el, double & Temperature)
{

    
    FILE * FileToRead;
    char line[500];
    char thrashchar;
    std::string trashstring;
    long double x, y, z, strength;
    unsigned source_number, order, mothersrc, motherwall;
    position_vector position;
    bool audible,legal;
    std::vector<source> sources;
    
    char* whole_filename_src = (char *) malloc(sizeof(char)*400);
    strcat(whole_filename_src,Directory); 
    strcat(whole_filename_src,filename);
    
    FileToRead = fopen (whole_filename_src, "r");  //fopen modes are "r" read, "w" write, "a" append, "r+" both reading and writing, "w+" empty for reading and writing, "a+" reading and appending
    if (FileToRead!=NULL)
    {   
        //Read Header Info
        fgets(line, 500, FileToRead);
        sscanf (line, "%s %s %lf %s %c %lf %s", &trashstring, &trashstring, &az, &trashstring, &thrashchar, &el, &trashstring);
        std::cout<<std::endl<<az<<" "<<el<<std::endl;
        fgets(line, 500, FileToRead);
        sscanf (line, "%s %lf", &trashstring, &Temperature); //Sometimes this needs to be commented out: specifically when temperature information is absent 
        std::cout<<std::endl<<Temperature<<std::endl;
        char * flag;
        flag=fgets(line, 500, FileToRead);
        
        flag=fgets(line, 500, FileToRead);
        
        //Reads a Single Source
        while(flag != NULL) /* get a line, up to 500 chars from fr.  done if NULL */
        {   
            sscanf (line, "%s %u  ", &trashstring, &source_number);
                    std::cout<<std::endl<<"SrcNumber: "<<source_number<<std::endl;
            flag=fgets(line, 500, FileToRead);
            sscanf (line, "%s %Lf %c %Lf %c %Lf  ", &trashstring, &x, &thrashchar, &y, &thrashchar, &z);
                    std::cout<<"SrcPosition: "<<x<<" "<<y<<" "<<z<<std::endl;
            flag=fgets(line, 500, FileToRead);
            sscanf (line, "%s %u  ", &trashstring, &order);
                    std::cout<<"Order: "<<order<<std::endl;
            flag=fgets(line, 500, FileToRead);
            sscanf (line, "%s %Lf  ", &trashstring, &strength);
                         std::cout<<"Strength: "<<strength<<std::endl;    
            flag=fgets(line, 500, FileToRead);
            sscanf (line, "%s %u  ", &trashstring, &mothersrc);
                        std::cout<<"MotherSource: "<<mothersrc<<std::endl; 
            flag=fgets(line, 500, FileToRead);
            sscanf (line, "%s %u  ", &trashstring, &order);
                        std::cout<<"MotherWall: "<<order<<std::endl; 
             flag=fgets(line, 500, FileToRead);
            flag=fgets(line, 500, FileToRead);
        }
        fclose (FileToRead);
    }
    




}

#endif
//NOTES

//Format information
//  %s = char*
//  %Lf = long double
//  %lf = double
//  %c = single character
//  %d = decimal integer