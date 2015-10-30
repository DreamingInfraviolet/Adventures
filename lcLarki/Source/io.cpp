#include <string>
#include <iostream>
#include "../JuceLibraryCode/JuceHeader.h"

void Inform(const std::string& message)
{
	juce::Logger::writeToLog(":-- " + message + "\n");
	
}

void Error(const std::string& message)
{
	juce::Logger::writeToLog("Error: " + message + "\n");
}


void Warning(const std::string& message)
{
	juce::Logger::writeToLog("Warning: " + message + "\n");
}
