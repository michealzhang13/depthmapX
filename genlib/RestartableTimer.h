// Copyright (C) 2017 Christian Sailer

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <chrono>

class RestartableTimer
{
public:
	RestartableTimer(bool running = false) : m_elapsedTime(0.0), m_running(running), m_count(0)
	{
		if (m_running) {
			start();
		}
	}

	void start() {
		if (!m_running) {
			m_running = true;
			m_startTime = std::chrono::high_resolution_clock::now();
		}
	}

	void stop() {
		if (m_running) {
			auto t2 = std::chrono::high_resolution_clock::now();
			m_elapsedTime += static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(t2 - m_startTime).count()) / 1000.0;
			m_running = false;
			m_count++;
		}
	}

	double getTimeInSeconds()
	{
		if (m_running) {
			stop();
		}
		return m_elapsedTime;
	}

	size_t getCount() const {
		return m_count;
	}


	void reset()
	{
		if (m_running) {
			stop();
		}
		m_elapsedTime = 0.0;
	}

private:
	double m_elapsedTime;
	bool m_running;
	size_t m_count;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
};
