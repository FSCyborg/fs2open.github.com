#include "AbstractDialogModel.h"
#include "missionui/missioncmdbrief.h"

namespace fso {
namespace fred {
namespace dialogs {


class CommandBriefingDialogModel: public AbstractDialogModel {
 public:

	CommandBriefingDialogModel(QObject* parent, EditorViewport* viewport);

	bool apply() override;
	void reject() override;

	SCP_string getBriefingText() { return _briefingText; }
	SCP_string getAnimationFilename() { return _animationFilename; }
	SCP_string getSpeechFilename() { return _speechFilename; }
	ubyte getCurrentTeam() { return _currentTeam; }

	void setBriefingText(const SCP_string& briefingText) { modify<SCP_string>(_briefingText, briefingText); }
	void setAnimationFilename(const SCP_string& animationFilename) { modify<SCP_string>(_animationFilename, animationFilename); }
	void setSpeechFilename(const SCP_string& speechFilename) { modify<SCP_string>(_speechFilename, speechFilename); }
	void setCurrentTeam(const ubyte& teamIn) {}; // not yet fully supported

	bool query_modified() const;
	void update_init();
	bool validate_data();

	bool hasMultipleStages() const;
 private:
	void initializeData();

	template<typename T>
	void modify(T &a, const T &b);

	SCP_string _briefingText;
	SCP_string _animationFilename;
	SCP_string _speechFilename;
	int _currentTeam;
	int _currentStage;
	int _totalStages;
	int _waveID;

	cmd_brief _command_brief;
};


template<typename T>
inline void CommandBriefingDialogModel::modify(T &a, const T &b) {
	if (a != b) {
		a = b;
		modelChanged();
	}
}

}
}
}