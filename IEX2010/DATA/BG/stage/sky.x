xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 45;
 0.00000;1018.88416;0.00000;,
 0.00000;927.53955;-459.22012;,
 324.71774;927.53955;-324.71774;,
 0.00000;1018.88416;0.00000;,
 459.22012;927.53955;0.00000;,
 0.00000;1018.88416;0.00000;,
 324.71774;927.53955;324.71774;,
 0.00000;1018.88416;0.00000;,
 0.00000;927.53955;459.22012;,
 0.00000;1018.88416;0.00000;,
 0.00000;927.53955;459.22012;,
 -324.71774;927.53955;324.71759;,
 -459.22012;927.53955;0.00000;,
 -324.71774;927.53955;-324.71759;,
 0.00000;927.53955;-459.22012;,
 0.00000;667.41180;-848.52820;,
 600.00000;667.41180;-600.00000;,
 848.52820;667.41180;0.00000;,
 600.00000;667.41180;600.00000;,
 -0.00012;667.41180;848.52820;,
 -0.00012;667.41180;848.52820;,
 -600.00012;667.41180;599.99994;,
 -848.52820;667.41180;0.00000;,
 -600.00012;667.41180;-599.99994;,
 0.00000;667.41180;-848.52820;,
 0.00000;278.10373;-1108.65552;,
 783.93781;278.10373;-783.93781;,
 1108.65552;278.10373;0.00000;,
 783.93781;278.10373;783.93781;,
 -0.00012;278.10373;1108.65552;,
 -0.00012;278.10373;1108.65552;,
 -783.93799;278.10373;783.93762;,
 -1108.65552;278.10373;0.00000;,
 -783.93799;278.10373;-783.93768;,
 0.00000;278.10373;-1108.65552;,
 0.00000;-181.11624;-1200.00000;,
 848.52820;-181.11624;-848.52820;,
 1200.00000;-181.11624;-0.00000;,
 848.52820;-181.11624;848.52820;,
 -0.00012;-181.11624;1200.00000;,
 -0.00012;-181.11624;1200.00000;,
 -848.52826;-181.11624;848.52802;,
 -1200.00000;-181.11624;0.00000;,
 -848.52826;-181.11624;-848.52802;,
 0.00000;-181.11624;-1200.00000;;
 
 32;
 3;0,1,2;,
 3;3,2,4;,
 3;5,4,6;,
 3;7,6,8;,
 3;9,10,11;,
 3;3,11,12;,
 3;5,12,13;,
 3;7,13,14;,
 4;1,15,16,2;,
 4;2,16,17,4;,
 4;4,17,18,6;,
 4;6,18,19,8;,
 4;10,20,21,11;,
 4;11,21,22,12;,
 4;12,22,23,13;,
 4;13,23,24,14;,
 4;15,25,26,16;,
 4;16,26,27,17;,
 4;17,27,28,18;,
 4;18,28,29,19;,
 4;20,30,31,21;,
 4;21,31,32,22;,
 4;22,32,33,23;,
 4;23,33,34,24;,
 4;25,35,36,26;,
 4;26,36,37,27;,
 4;27,37,38,28;,
 4;28,38,39,29;,
 4;30,40,41,31;,
 4;31,41,42,32;,
 4;32,42,43,33;,
 4;33,43,44,34;;
 
 MeshMaterialList {
  1;
  32;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   19.000000;
   0.220000;0.220000;0.220000;;
   0.560000;0.560000;0.560000;;
   TextureFilename {
    "blue-sky.png";
   }
  }
 }
 MeshNormals {
  33;
  0.000000;-1.000000;0.000000;,
  0.000000;-0.924735;0.380611;,
  -0.269133;-0.924735;0.269133;,
  -0.380611;-0.924735;0.000000;,
  -0.269133;-0.924735;-0.269133;,
  0.000000;-0.924735;-0.380611;,
  0.269133;-0.924735;-0.269133;,
  0.380611;-0.924735;-0.000000;,
  0.269133;-0.924735;0.269133;,
  0.000000;-0.709230;0.704977;,
  -0.498494;-0.709230;0.498494;,
  -0.704977;-0.709230;0.000000;,
  -0.498494;-0.709230;-0.498494;,
  0.000000;-0.709230;-0.704977;,
  0.498494;-0.709230;-0.498494;,
  0.704977;-0.709230;-0.000000;,
  0.498494;-0.709230;0.498494;,
  0.000000;-0.384551;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;0.000000;,
  -0.652733;-0.384551;-0.652733;,
  0.000000;-0.384551;-0.923104;,
  0.652733;-0.384551;-0.652733;,
  0.923104;-0.384551;-0.000000;,
  0.652733;-0.384551;0.652733;,
  0.000000;-0.195090;0.980785;,
  -0.693520;-0.195090;0.693520;,
  -0.980785;-0.195090;0.000000;,
  -0.693520;-0.195090;-0.693520;,
  0.000000;-0.195090;-0.980785;,
  0.693520;-0.195090;-0.693520;,
  0.980785;-0.195090;-0.000000;,
  0.693520;-0.195090;0.693520;;
  32;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,7;,
  3;0,7,8;,
  3;0,8,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,16,8;,
  4;8,16,9,1;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,24,16;,
  4;16,24,17,9;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,32,24;,
  4;24,32,25,17;;
 }
 MeshTextureCoords {
  45;
  0.158740;0.012080;,
  0.038000;0.183130;,
  0.279480;0.183130;,
  0.400220;0.012080;,
  0.520950;0.183130;,
  0.641690;0.012080;,
  0.762430;0.183130;,
  0.883170;0.012080;,
  1.003910;0.183130;,
  0.160080;0.012080;,
  0.003910;0.183130;,
  0.245390;0.183130;,
  0.486870;0.183130;,
  0.728350;0.183130;,
  0.969820;0.183130;,
  0.003130;0.350890;,
  0.251560;0.350890;,
  0.499980;0.350890;,
  0.748400;0.350890;,
  0.996830;0.350890;,
  -0.003170;0.350890;,
  0.245250;0.350890;,
  0.493670;0.350890;,
  0.742100;0.350890;,
  0.990520;0.350890;,
  0.003130;0.675750;,
  0.251560;0.675750;,
  0.499980;0.675750;,
  0.748400;0.675750;,
  0.996830;0.675750;,
  -0.003170;0.675750;,
  0.245250;0.675750;,
  0.493670;0.675750;,
  0.742100;0.675750;,
  0.990520;0.675750;,
  0.003130;1.000610;,
  0.251560;1.000610;,
  0.499980;1.000610;,
  0.748400;1.000610;,
  0.996830;1.000610;,
  -0.003170;1.000610;,
  0.245250;1.000610;,
  0.493670;1.000610;,
  0.742100;1.000610;,
  0.990520;1.000610;;
 }
 MeshVertexColors {
  45;
  0;1.000000;1.000000;1.000000;1.000000;,
  1;1.000000;1.000000;1.000000;1.000000;,
  2;1.000000;1.000000;1.000000;1.000000;,
  3;1.000000;1.000000;1.000000;1.000000;,
  4;1.000000;1.000000;1.000000;1.000000;,
  5;1.000000;1.000000;1.000000;1.000000;,
  6;1.000000;1.000000;1.000000;1.000000;,
  7;1.000000;1.000000;1.000000;1.000000;,
  8;1.000000;1.000000;1.000000;1.000000;,
  9;1.000000;1.000000;1.000000;1.000000;,
  10;1.000000;1.000000;1.000000;1.000000;,
  11;1.000000;1.000000;1.000000;1.000000;,
  12;1.000000;1.000000;1.000000;1.000000;,
  13;1.000000;1.000000;1.000000;1.000000;,
  14;1.000000;1.000000;1.000000;1.000000;,
  15;1.000000;1.000000;1.000000;1.000000;,
  16;1.000000;1.000000;1.000000;1.000000;,
  17;1.000000;1.000000;1.000000;1.000000;,
  18;1.000000;1.000000;1.000000;1.000000;,
  19;1.000000;1.000000;1.000000;1.000000;,
  20;1.000000;1.000000;1.000000;1.000000;,
  21;1.000000;1.000000;1.000000;1.000000;,
  22;1.000000;1.000000;1.000000;1.000000;,
  23;1.000000;1.000000;1.000000;1.000000;,
  24;1.000000;1.000000;1.000000;1.000000;,
  25;1.000000;1.000000;1.000000;1.000000;,
  26;1.000000;1.000000;1.000000;1.000000;,
  27;1.000000;1.000000;1.000000;1.000000;,
  28;1.000000;1.000000;1.000000;1.000000;,
  29;1.000000;1.000000;1.000000;1.000000;,
  30;1.000000;1.000000;1.000000;1.000000;,
  31;1.000000;1.000000;1.000000;1.000000;,
  32;1.000000;1.000000;1.000000;1.000000;,
  33;1.000000;1.000000;1.000000;1.000000;,
  34;1.000000;1.000000;1.000000;1.000000;,
  35;1.000000;1.000000;1.000000;1.000000;,
  36;1.000000;1.000000;1.000000;1.000000;,
  37;1.000000;1.000000;1.000000;1.000000;,
  38;1.000000;1.000000;1.000000;1.000000;,
  39;1.000000;1.000000;1.000000;1.000000;,
  40;1.000000;1.000000;1.000000;1.000000;,
  41;1.000000;1.000000;1.000000;1.000000;,
  42;1.000000;1.000000;1.000000;1.000000;,
  43;1.000000;1.000000;1.000000;1.000000;,
  44;1.000000;1.000000;1.000000;1.000000;;
 }
}
