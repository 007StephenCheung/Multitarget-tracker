#pragma once
#include "Kalman.h"
#include "HungarianAlg.h"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

class CTrack
{
public:
	std::vector<cv::Point2d> trace;
	static size_t NextTrackID;
	size_t track_id;
	size_t skipped_frames; 
	cv::Point2d prediction;
	TKalmanFilter* KF;
	CTrack(cv::Point2f p, float dt, float Accel_noise_mag);
	~CTrack();
};


class CTracker
{
public:
	
	// ��� ������� ������ �������
	float dt; 

	float Accel_noise_mag;

	// ����� ����������. ���� ����� ��������� ��� �� ����� �� ����������,
	// ����������� ���� �����, �� ��� ���� �� ��������������� � ������ � �����������.
	double dist_thres;
	// ������������ ���������� ������ ������� ���� ����������� �� ������� ������ � ���������.
	int maximum_allowed_skipped_frames;
	// ������������ ����� �����
	int max_trace_length;

	std::vector<CTrack*> tracks;
	void Update(std::vector<cv::Point2d>& detections);
	CTracker(float _dt, float _Accel_noise_mag, double _dist_thres=60, int _maximum_allowed_skipped_frames=10,int _max_trace_length=10);
	~CTracker(void);
};

