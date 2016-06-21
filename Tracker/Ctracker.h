#pragma once
#include "Kalman.h"
#include "HungarianAlg.h"
#include "defines.h"
#include <iostream>
#include <vector>
#include <memory>

class CTrack
{
public:
	std::vector<Point_t> trace;
	static size_t NextTrackID;
	size_t track_id;
	size_t skipped_frames; 
	Point_t prediction;
	TKalmanFilter* KF;
	CTrack(Point_t p, track_t dt, track_t Accel_noise_mag);
	~CTrack();
};


class CTracker
{
public:
	
	// ��� ������� ������ �������
	track_t dt;

	track_t Accel_noise_mag;

	// ����� ����������. ���� ����� ��������� ��� �� ����� �� ����������,
	// ����������� ���� �����, �� ��� ���� �� ��������������� � ������ � �����������.
	track_t dist_thres;
	// ������������ ���������� ������ ������� ���� ����������� �� ������� ������ � ���������.
	int maximum_allowed_skipped_frames;
	// ������������ ����� �����
	int max_trace_length;

	std::vector<std::unique_ptr<CTrack>> tracks;
	void Update(std::vector<Point_t>& detections);
	CTracker(track_t _dt, track_t _Accel_noise_mag, track_t _dist_thres = 60, int _maximum_allowed_skipped_frames = 10, int _max_trace_length = 10);
	~CTracker(void);
};

