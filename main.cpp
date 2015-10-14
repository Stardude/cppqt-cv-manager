#include <iostream>
#include <string>
#include <array>
#include <vector>

class JobRecord
{
private:
	int mStartYear;
	int mEndYear;
	std::string mJobTitle;
	std::string mCompanyName;
public:
	JobRecord(int _mStartYear, int _mEndYear, std::string _mJobTitle, std::string _mCompanyName) :
		mStartYear{ _mStartYear },
		mEndYear{ _mEndYear },
		mJobTitle{ _mJobTitle },
		mCompanyName{ _mCompanyName }
	{

	}
	bool isValid() const
	{
		if (mStartYear > 1960 &&
			mEndYear > 1960 &&
			!mJobTitle.empty() &&
			!mCompanyName.empty()) return true;
		else return false;
	}

	void print() const
	{
		if (isValid())
			std::cout << "(" << mStartYear << " - " << mEndYear << ")"
			<< std::endl << "Title: " << mJobTitle
			<< std::endl << "Name of the Company: " << mCompanyName
			<< std::endl << std::endl;
	}
};

class CV
{
public:
	CV(const std::string &name, int birthYear, const std::string &skills)
	{
		mName = name;
		mBirthYear = birthYear;
		mSkills = skills;
	}

	bool isValid() const
	{
		return !mName.empty()
			&& ((mBirthYear > 1963) && (mBirthYear < 1995))
			&& !mSkills.empty();
	}

	void print() const
	{
		if (isValid())
		{
			std::cout << mName << " (" << mBirthYear << ")" << std::endl;
			std::cout << "=====================" << std::endl;
			std::cout << "Skills: " << mSkills << std::endl;
			std::cout << "Previous work record: " << std::endl;
			jobRecords();
			std::cout << std::endl << std::endl;
		}
	}

	void addJobRecord(JobRecord jr)
	{
		mPreviousJobs.push_back(jr);
	}

	void jobRecords() const
	{
		for (const auto& jr : mPreviousJobs)
		{
			if (jr.isValid())
			{
				jr.print();
			}

		}
	}
private:
	std::string mName;
	int mBirthYear;
	std::string mSkills;
	std::vector<JobRecord> mPreviousJobs;
};




int main()
{
	CV johnsCV{ "John Jonson", 1978,"C++, Java" };
	JobRecord johnsJR1{ 1996,2002,"senior","Microsoft" };
	JobRecord johnsJR2{ 1990,1995,"junior","IBM" };
	johnsCV.addJobRecord(johnsJR1);
	johnsCV.addJobRecord(johnsJR2);

	CV dansCV("Dan Davidson", 1988, "C++, Java"/*, "IBM 1996-1997"*/);
	JobRecord dansJR1{ 1996,1997,"developer","IBM" };
	dansCV.addJobRecord(dansJR1);

	CV willsCV{ "Will Walker", 1971, "C++, Java"/*, "IBM 1990-1999; Microsoft 1999-2010" */};
	JobRecord willsJR1{ 1990, 1999, "junior developer", "IBM" };
	JobRecord willsJR2{ 1999, 2010, "senior software developer", "Microsoft" };
	willsCV.addJobRecord(willsJR1);
	willsCV.addJobRecord(willsJR2);

	std::vector<CV> cvList{ johnsCV, dansCV, willsCV };

	for (const auto& cv : cvList)
	{
		if (cv.isValid())
		{
			cv.print();
		}
		else
		{
			std::cout << "ERROR: CV is invalid" << std::endl;
		}
	}

	return 0;
}

