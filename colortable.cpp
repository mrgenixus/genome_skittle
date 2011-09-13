#include "colortable.h"
#include <map>
#include "Color.h"

using namespace std;
using namespace skittle;

ColorTable::ColorTable()
{
    //based on: http://www.eyesopen.com/docs/html/vida/manual/Ch3DDisplaySubSecMoleculeProteins.html#SECTION0079212000000000000000
    //[1]  http://www.eyesopen.com/docs/html/vida/manual/node85.html#shapely
    currentColors[ (int)'A' ] = Color(140, 255, 140);//Alanine
    //currentColors[ (int)'B' ] = Color(255,255,255);//	UNUSED
    currentColors[ (int)'C' ] = Color(255, 255, 112);//Cysteine
    currentColors[ (int)'D' ] = Color(160, 0, 66);//Aspartic Acid
    currentColors[ (int)'E' ] = Color(102, 0, 0);//GLutamic Acid
    currentColors[ (int)'F' ] = Color(83, 76, 66);//Phenylalanine
    currentColors[ (int)'G' ] = Color(255, 255, 255);//Glycine
    currentColors[ (int)'H' ] = Color(112, 112, 255);//histidine
    currentColors[ (int)'I' ] = Color(0, 76, 0);//Isoleucine
    //currentColors[ (int)'J' ] = Color( 255,255,255);//	UNUSED
    currentColors[ (int)'K' ] = Color(71, 71, 184);//lysine
    //currentColors[ (int)'L' ] = Color(69, 94, 69);//	UNUSED
    currentColors[ (int)'M' ] = Color(184, 160, 66);//Methionine
    currentColors[ (int)'N' ] = Color(255, 124, 112);//Asparagine
    //currentColors[ (int)'O' ] = Color( 255,255,255);//	UNUSED
    currentColors[ (int)'P' ] = Color(82, 82, 82);//Proline
    currentColors[ (int)'Q' ] = Color(255, 76, 76);//Glutamine GLN
    currentColors[ (int)'R' ] = Color(0, 0, 124);//Arginine
    currentColors[ (int)'S' ] = Color(255, 112, 66);//Serine
    currentColors[ (int)'T' ] = Color(184, 76, 0);//Threonine
    //currentColors[ (int)'U' ] = Color( 255,255,255);//	UNUSED
    currentColors[ (int)'V' ] = Color(255, 140, 255);//Valine
    currentColors[ (int)'W' ] = Color(79, 70, 0);//Tryptophan
    //currentColors[ (int)'X' ] = Color( 255,255,255);//	UNUSED
    currentColors[ (int)'Y' ] = Color(140, 112, 76);//Tyrosine TYR
    //currentColors[ (int)'Z' ] = Color( 255,255,255);//	UNUSED


    //Override previous values
    currentColors[ (int)'A' ] = Color(0, 0, 0);//BLACK - Adenine
    currentColors[ (int)'C' ] = Color(255, 0, 0);//RED - Cytosine
    currentColors[ (int)'G' ] = Color(0, 255, 0);//GREEN - Guanine
    currentColors[ (int)'T' ] = Color(0, 0, 255);//BLUE - Thymine
    currentColors[ (int)'N' ] = Color( 50, 50, 50);//not sequenced*/
}

Color ColorTable::getColor(char nucleotide) {
    return currentColors[(int)((unsigned char)nucleotide)];
}
