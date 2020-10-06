#ifndef API_MARKERLABEL_H_1906150905
#define API_MARKERLABEL_H_1906150905

#ifdef API_MARKERLABEL_EXPORTS
#define MARKERLABEL_API __declspec(dllexport)
#else
#define MARKERLABEL_API __declspec(dllimport)
#pragma comment(lib, "API_MarkerLabel_vc140_md_dll_64r_unicode.lib")
#endif


#include"API_ComBaseType.h"

typedef unsigned char BYTE;
class MARKERLABEL_API API_MarkerLabel
{
public:
    API_MarkerLabel();
	~API_MarkerLabel();

	//
	enum  Marker_Type{
		MARKER_TYPE_CARD_RING_15_428 = 0x0010, //15 ring 428 card
	};

	struct Option
	{
		bool ignore_markers_with_valid_id = true;    // ignore the code id>=0 Markers
		int ring_code_splite_number = 14; //Ring Coded Splite Number --- Tritop: 15,  Aicon: 14
		float ring_black_center_ratio = 2.0; // the black region of the ring , the ratio to radius
		float ring_white_cener_ratio = 2.5;// 
		float ring_min_value = false;// make up the map id 
	};

public:
	int reset_id(EllipseMarker* pMarker2ds, int num_marker);

	void clear_repeate_id(EllipseMarker* pMarker2ds, int num_marker);

    int  auto_label(EllipseMarker* pMarker2ds, int num_marker,
        int image_width, int image_height,     // the width and height of image
        int marker_type, Option & options,     // marker type and parameter
        BYTE *ptr_src_8bit_image = nullptr,     // src image
        Marker3D * pMarker3d=nullptr,          // marker3d optium 
        int num_marker3d=0);

	void save_marker(EllipseMarker* pMarker2ds, int num_marker, const char *wstrFilePath); // 
private:
	void* m_core;
};


#endif