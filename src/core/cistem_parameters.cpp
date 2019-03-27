#include "core_headers.h"
#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(ArrayOfcisTEMParameterLines);

cisTEMParameterLine::cisTEMParameterLine()
{
	SetAllToZero();
}

/* Should never be needed actually
void cisTEMParameterLine::SwapPsiAndPhi()
{
	float temp_float = psi;
	psi = phi;
	phi = temp_float;
}*/

void cisTEMParameterLine::Add(cisTEMParameterLine &line_to_add)
{
	position_in_stack += line_to_add.position_in_stack;
	image_is_active += line_to_add.image_is_active;
	psi += line_to_add.psi;
	theta += line_to_add.theta;
	phi += line_to_add.phi;
	x_shift += line_to_add.x_shift;
	y_shift += line_to_add.y_shift;
	defocus_1 += line_to_add.defocus_1;
	defocus_2 += line_to_add.defocus_2;
	defocus_angle += line_to_add.defocus_angle;
	phase_shift += line_to_add.phase_shift;
	occupancy += line_to_add.occupancy;
	logp += line_to_add.logp;
	sigma += line_to_add.sigma;
	score += line_to_add.score;
	score_change += line_to_add.score_change;
	pixel_size += line_to_add.pixel_size;
	microscope_voltage_kv += line_to_add.microscope_voltage_kv;
	microscope_spherical_aberration_mm += line_to_add.microscope_spherical_aberration_mm;
	beam_tilt_x += line_to_add.beam_tilt_x;
	beam_tilt_y += line_to_add.beam_tilt_y;
	image_shift_x += line_to_add.image_shift_x;
	image_shift_y += line_to_add.image_shift_y;
}

void cisTEMParameterLine::Subtract(cisTEMParameterLine &line_to_add)
{
	position_in_stack -= line_to_add.position_in_stack;
	image_is_active -= line_to_add.image_is_active;
	psi -= line_to_add.psi;
	theta -= line_to_add.theta;
	phi -= line_to_add.phi;
	x_shift -= line_to_add.x_shift;
	y_shift -= line_to_add.y_shift;
	defocus_1 -= line_to_add.defocus_1;
	defocus_2 -= line_to_add.defocus_2;
	defocus_angle -= line_to_add.defocus_angle;
	phase_shift -= line_to_add.phase_shift;
	occupancy -= line_to_add.occupancy;
	logp -= line_to_add.logp;
	sigma -= line_to_add.sigma;
	score -= line_to_add.score;
	score_change -= line_to_add.score_change;
	pixel_size -= line_to_add.pixel_size;
	microscope_voltage_kv -= line_to_add.microscope_voltage_kv;
	microscope_spherical_aberration_mm -= line_to_add.microscope_spherical_aberration_mm;
	beam_tilt_x -= line_to_add.beam_tilt_x;
	beam_tilt_y -= line_to_add.beam_tilt_y;
	image_shift_x -= line_to_add.image_shift_x;
	image_shift_y -= line_to_add.image_shift_y;
}

void cisTEMParameterLine::AddSquare(cisTEMParameterLine &line_to_add)
{
	position_in_stack += powf(line_to_add.position_in_stack, 2);
	image_is_active += powf(line_to_add.image_is_active, 2);
	psi += powf(line_to_add.psi, 2);
	theta += powf(line_to_add.theta, 2);
	phi += powf(line_to_add.phi, 2);
	x_shift += powf(line_to_add.x_shift, 2);
	y_shift += powf(line_to_add.y_shift, 2);
	defocus_1 += powf(line_to_add.defocus_1, 2);
	defocus_2 += powf(line_to_add.defocus_2, 2);
	defocus_angle += powf(line_to_add.defocus_angle, 2);
	phase_shift += powf(line_to_add.phase_shift, 2);
	occupancy += powf(line_to_add.occupancy, 2);
	logp += powf(line_to_add.logp, 2);
	sigma += powf(line_to_add.sigma, 2);
	score += powf(line_to_add.score, 2);
	score_change += powf(line_to_add.score_change, 2);
	pixel_size += powf(line_to_add.pixel_size, 2);
	microscope_voltage_kv += powf(line_to_add.microscope_voltage_kv, 2);
	microscope_spherical_aberration_mm += powf(line_to_add.microscope_spherical_aberration_mm, 2);
	beam_tilt_x += powf(line_to_add.beam_tilt_x, 2);
	beam_tilt_y = powf(line_to_add.beam_tilt_y, 2);
	image_shift_x += powf(line_to_add.image_shift_x, 2);
	image_shift_y += powf(line_to_add.image_shift_y, 2);

}

void cisTEMParameterLine::SetAllToZero()
{
	position_in_stack = 0;
	image_is_active = 0;
	psi = 0.0f;
	theta = 0.0f;
	phi = 0.0f;
	x_shift = 0.0f;
	y_shift = 0.0f;
	defocus_1 = 0.0f;
	defocus_2 = 0.0f;
	defocus_angle = 0.0f;
	phase_shift = 0.0f;
	occupancy = 0.0f;
	logp = 0.0f;
	sigma = 0.0f;
	score = 0.0f;
	score_change = 0.0f;
	pixel_size = 0.0f;
	microscope_voltage_kv = 0.0f;
	microscope_spherical_aberration_mm = 0.0f;
	beam_tilt_x = 0.0f;
	beam_tilt_y = 0.0f;
	image_shift_x = 0.0f;
	image_shift_y = 0.0f;
}

void cisTEMParameterLine::ReplaceNanAndInfWithOther(cisTEMParameterLine &other_params)
{
	if (isnanf(psi) || isinff(psi)) psi = other_params.psi;
	if (isnanf(theta) || isinff(theta)) theta = other_params.theta;
	if (isnanf(phi) || isinff(phi)) phi = other_params.phi;
	if (isnanf(x_shift) || isinff(x_shift)) x_shift = other_params.x_shift;
	if (isnanf(y_shift) || isinff(y_shift)) y_shift = other_params.y_shift;
	if (isnanf(defocus_1) || isinff(defocus_1)) defocus_1 = other_params.defocus_1;
	if (isnanf(defocus_2) || isinff(defocus_2)) defocus_2 = other_params.defocus_2;
	if (isnanf(defocus_angle) || isinff(defocus_angle)) defocus_angle = other_params.defocus_angle;
	if (isnanf(phase_shift) || isinff(phase_shift)) phase_shift = other_params.phase_shift;
	if (isnanf(occupancy) || isinff(occupancy)) occupancy = other_params.occupancy;
	if (isnanf(logp) || isinff(logp)) logp = other_params.logp;
	if (isnanf(sigma) || isinff(sigma)) sigma = other_params.sigma;
	if (isnanf(score) || isinff(score)) score = other_params.score;
	if (isnanf(score_change) || isinff(score_change)) score_change = other_params.score_change;
	if (isnanf(pixel_size) || isinff(pixel_size)) pixel_size = other_params.pixel_size;
	if (isnanf(microscope_voltage_kv) || isinff(microscope_voltage_kv)) microscope_voltage_kv = other_params.microscope_voltage_kv;
	if (isnanf(microscope_spherical_aberration_mm) || isinff(microscope_spherical_aberration_mm)) microscope_spherical_aberration_mm = other_params.microscope_spherical_aberration_mm;
	if (isnanf(beam_tilt_x) || isinff(beam_tilt_x)) beam_tilt_x = other_params.beam_tilt_x;
	if (isnanf(beam_tilt_y) || isinff(beam_tilt_y)) beam_tilt_y = other_params.beam_tilt_y;
	if (isnanf(image_shift_x) || isinff(image_shift_x)) image_shift_x = other_params.image_shift_x;
	if (isnanf(image_shift_y) || isinff(image_shift_y)) image_shift_y = other_params.image_shift_y;


}

cisTEMParameterLine::~cisTEMParameterLine()
{

}

cisTEMParameters::cisTEMParameters()
{

}

cisTEMParameters::~cisTEMParameters()
{

}

void cisTEMParameters::PreallocateMemoryAndBlank(int number_to_allocate)
{
	ClearAll();
	cisTEMParameterLine temp_line;
	all_parameters.Add(temp_line, number_to_allocate);
}

void cisTEMParameters::ReadFromFrealignParFile(wxString wanted_filename, float wanted_pixel_size, float wanted_microscope_voltage, float wanted_microscope_cs, float wanted_beam_tilt_x, float wanted_beam_tilt_y, float wanted_image_shift_x, float wanted_image_shift_y)
{
	ClearAll();
	float input_parameters[17];

	FrealignParameterFile input_par_file(wanted_filename, OPEN_TO_READ);
	input_par_file.ReadFile(false, -1);

	// pre-allocate the stack...

	PreallocateMemoryAndBlank(input_par_file.number_of_lines);

	// fill the array..

	for (long counter = 0; counter < input_par_file.number_of_lines; counter++)
	{
		input_par_file.ReadLine(input_parameters);

		all_parameters[counter].position_in_stack = input_parameters[0];
		all_parameters[counter].psi = input_parameters[1];
		all_parameters[counter].theta = input_parameters[2];
		all_parameters[counter].phi = input_parameters[3];
		all_parameters[counter].x_shift = input_parameters[4];
		all_parameters[counter].y_shift = input_parameters[5];
		all_parameters[counter].image_is_active = int(input_parameters[7]);
		all_parameters[counter].defocus_1 = input_parameters[8];
		all_parameters[counter].defocus_2 = input_parameters[9];
		all_parameters[counter].defocus_angle = input_parameters[10];
		all_parameters[counter].phase_shift = input_parameters[11];
		all_parameters[counter].occupancy = input_parameters[12];
		all_parameters[counter].logp = input_parameters[13];
		all_parameters[counter].sigma = input_parameters[14];
		all_parameters[counter].score = input_parameters[15];
		all_parameters[counter].score_change = input_parameters[16];
		all_parameters[counter].pixel_size = wanted_pixel_size; // not there
		all_parameters[counter].microscope_voltage_kv = wanted_microscope_voltage; // not there
		all_parameters[counter].microscope_spherical_aberration_mm = wanted_microscope_cs; // not there
		all_parameters[counter].beam_tilt_x = wanted_beam_tilt_x; // not there
		all_parameters[counter].beam_tilt_y = wanted_beam_tilt_y; // not there
		all_parameters[counter].image_shift_x = wanted_image_shift_x; // not there
		all_parameters[counter].image_shift_y = wanted_image_shift_y; // not there
	}
}

void cisTEMParameters::ReadFromcisTEMStarFile(wxString wanted_filename, bool exclude_negative_film_numbers)
{
	cisTEMParameterLine temp_line;
	all_parameters.Clear();
	cisTEMStarFileReader star_reader(wanted_filename, &all_parameters, exclude_negative_film_numbers);
}

void cisTEMParameters::AddCommentToHeader(wxString comment_to_add)
{
	if (comment_to_add.StartsWith("#") == false)
	{
		comment_to_add = "# " + comment_to_add;
	}

	comment_to_add.Trim(true);
	header_comments.Add(comment_to_add);
}

void cisTEMParameters::ClearAll()
{
	header_comments.Clear();
	all_parameters.Clear();
}

void cisTEMParameters::WriteTocisTEMStarFile(wxString wanted_filename)
{

	wxFileName cisTEM_star_filename = wanted_filename;
	cisTEM_star_filename.SetExt("star");
	long particle_counter;

	wxTextFile *cisTEM_star_file = new wxTextFile(cisTEM_star_filename.GetFullPath());

	if (cisTEM_star_file->Exists())
	{
		cisTEM_star_file->Open();
		cisTEM_star_file->Clear();
	}
	else
	{
		cisTEM_star_file->Create();
	}

	cisTEM_star_file->AddLine(wxString::Format("# Written by cisTEM Version %s on %s", CISTEM_VERSION_TEXT, wxDateTime::Now().FormatISOCombined(' ')));

	for (int counter = 0; counter < header_comments.GetCount(); counter++)
	{
		cisTEM_star_file->AddLine(header_comments[counter]);
	}


	// Write headers
	cisTEM_star_file->AddLine(wxString(" "));
	cisTEM_star_file->AddLine(wxString("data_"));
	cisTEM_star_file->AddLine(wxString(" "));
	cisTEM_star_file->AddLine(wxString("loop_"));
	cisTEM_star_file->AddLine(wxString("_cisTEMPositionInStack #1"));
	cisTEM_star_file->AddLine(wxString("_cisTEMAnglePsi #2"));
	cisTEM_star_file->AddLine(wxString("_cisTEMAngleTheta #3"));
	cisTEM_star_file->AddLine(wxString("_cisTEMAnglePhi #4"));
	cisTEM_star_file->AddLine(wxString("_cisTEMXShift #5"));
	cisTEM_star_file->AddLine(wxString("_cisTEMYShift #6"));
	cisTEM_star_file->AddLine(wxString("_cisTEMDefocus1 #7"));
	cisTEM_star_file->AddLine(wxString("_cisTEMDefocus2 #8"));
	cisTEM_star_file->AddLine(wxString("_cisTEMDefocusAngle #9"));
	cisTEM_star_file->AddLine(wxString("_cisTEMPhaseShift #10"));
	cisTEM_star_file->AddLine(wxString("_cisTEMImageActivity #11"));
	cisTEM_star_file->AddLine(wxString("_cisTEMOccupancy #12"));
	cisTEM_star_file->AddLine(wxString("_cisTEMLogP #13"));
	cisTEM_star_file->AddLine(wxString("_cisTEMSigma #14"));
	cisTEM_star_file->AddLine(wxString("_cisTEMScore #15"));
	cisTEM_star_file->AddLine(wxString("_cisTEMScoreChange #16"));
	cisTEM_star_file->AddLine(wxString("_cisTEMPixelSize #17"));
	cisTEM_star_file->AddLine(wxString("_cisTEMMicroscopeVoltagekV #18"));
	cisTEM_star_file->AddLine(wxString("_cisTEMMicroscopeCsMM #19"));
	cisTEM_star_file->AddLine(wxString("_cisTEMBeamTiltX #20"));
	cisTEM_star_file->AddLine(wxString("_cisTEMBeamTiltY #21"));
	cisTEM_star_file->AddLine(wxString("_cisTEMImageShiftX #22"));
	cisTEM_star_file->AddLine(wxString("_cisTEMImageShiftY #23"));


	cisTEM_star_file->AddLine("#            PSI   THETA     PHI       SHX       SHY      DF1      DF2  ANGAST  PSHIFT  STAT     OCC      LogP      SIGMA   SCORE  CHANGE    PSIZE    VOLT      CS  BTILTX  BTILTY  ISHFTX  ISHFTY");


	for (particle_counter = 0; particle_counter < all_parameters.GetCount(); particle_counter ++ )
	{
		cisTEM_star_file->AddLine(wxString::Format("%8u %7.2f %7.2f %7.2f %9.2f %9.2f %8.1f %8.1f %7.2f %7.2f %5i %7.2f %9i %10.4f %7.2f %7.2f %8.5f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f",	all_parameters[particle_counter].position_in_stack,
																														all_parameters[particle_counter].psi,
																														all_parameters[particle_counter].theta,
																														all_parameters[particle_counter].phi,
																														all_parameters[particle_counter].x_shift,
																														all_parameters[particle_counter].y_shift,
																														all_parameters[particle_counter].defocus_1,
																														all_parameters[particle_counter].defocus_2,
																														all_parameters[particle_counter].defocus_angle,
																														all_parameters[particle_counter].phase_shift,
																														all_parameters[particle_counter].image_is_active,
																														all_parameters[particle_counter].occupancy,
																														int(all_parameters[particle_counter].logp),
																														all_parameters[particle_counter].sigma,
																														all_parameters[particle_counter].score,
																														all_parameters[particle_counter].score_change,
																														all_parameters[particle_counter].pixel_size,
																														all_parameters[particle_counter].microscope_voltage_kv,
																														all_parameters[particle_counter].microscope_spherical_aberration_mm,
																														all_parameters[particle_counter].beam_tilt_x,
																														all_parameters[particle_counter].beam_tilt_y,
																														all_parameters[particle_counter].image_shift_x,
																														all_parameters[particle_counter].image_shift_y));



	}

	cisTEM_star_file->Write();
	cisTEM_star_file->Close();

	delete  cisTEM_star_file;

}

cisTEMParameterLine cisTEMParameters::ReturnParameterAverages(bool only_average_active)
{
	cisTEMParameterLine average_values;

	long 			average_position_in_stack = 0;
	long			average_image_is_active = 0;
	double		 	average_psi = 0.0;
	double			average_theta = 0.0;
	double			average_phi = 0.0;
	double			average_x_shift = 0.0;
	double			average_y_shift = 0.0;
	double			average_defocus_1 = 0.0;
	double			average_defocus_2 = 0.0;
	double			average_defocus_angle = 0.0;
	double			average_phase_shift = 0.0;
	double			average_occupancy = 0.0;
	double			average_logp = 0;
	double			average_sigma = 0.0;
	double 			average_score = 0.0;
	double			average_score_change = 0.0;
	double			average_pixel_size = 0.0;
	double			average_microscope_voltage_kv = 0.0;
	double			average_microscope_spherical_aberration_mm = 0.0;
	double			average_beam_tilt_x = 0.0;
	double			average_beam_tilt_y = 0.0;
	double			average_image_shift_x = 0.0;
	double			average_image_shift_y = 0.0;

	long number_summed = 0;

	for (long counter = 0; counter < all_parameters.GetCount(); counter++)
	{
		if (ReturnImageIsActive(counter) >= 0 || only_average_active == false)
		{
			average_position_in_stack += ReturnPositionInStack(counter);
			average_image_is_active += ReturnImageIsActive(counter);
			average_psi += ReturnPsi(counter);
			average_theta += ReturnTheta(counter);
			average_phi += ReturnPhi(counter);
			average_x_shift += ReturnXShift(counter);
			average_y_shift += ReturnYShift(counter);
			average_defocus_1 += ReturnDefocus1(counter);
			average_defocus_2 += ReturnDefocus2(counter);
			average_defocus_angle += ReturnDefocusAngle(counter);
			average_phase_shift += ReturnPhaseShift(counter);
			average_occupancy += ReturnOccupancy(counter);
			average_logp += ReturnLogP(counter);
			average_sigma += ReturnSigma(counter);
			average_score += ReturnScore(counter);
			average_score_change += ReturnScoreChange(counter);
			average_pixel_size += ReturnPixelSize(counter);
			average_microscope_voltage_kv += ReturnMicroscopekV(counter);
			average_microscope_spherical_aberration_mm += ReturnMicroscopeCs(counter);
			average_beam_tilt_x += ReturnBeamTiltX(counter);
			average_beam_tilt_y += ReturnBeamTiltY(counter);
			average_image_shift_x += ReturnImageShiftX(counter);
			average_image_shift_y += ReturnImageShiftY(counter);

			number_summed++;


		}

	}

	if (number_summed > 0)
	{
		average_values.position_in_stack = average_position_in_stack / double(number_summed);
		average_values.image_is_active = average_image_is_active / double(number_summed);
		average_values.psi = average_psi  / double(number_summed);
		average_values.theta = average_theta  / double(number_summed);
		average_values.phi = average_phi  / double(number_summed);
		average_values.x_shift = average_x_shift  / double(number_summed);
		average_values.y_shift = average_y_shift  / double(number_summed);
		average_values.defocus_1 = average_defocus_1  / double(number_summed);
		average_values.defocus_2 = average_defocus_2  / double(number_summed);
		average_values.defocus_angle = average_defocus_angle  / double(number_summed);
		average_values.phase_shift = average_phase_shift  / double(number_summed);
		average_values.occupancy = average_occupancy  / double(number_summed);
		average_values.logp = average_logp  / double(number_summed);
		average_values.sigma = average_sigma  / double(number_summed);
		average_values.score = average_score  / double(number_summed);
		average_values.score_change = average_score_change  / double(number_summed);
		average_values.pixel_size = average_pixel_size  / double(number_summed);
		average_values.microscope_voltage_kv = average_microscope_voltage_kv  / double(number_summed);
		average_values.microscope_spherical_aberration_mm = average_microscope_spherical_aberration_mm  / double(number_summed);
		average_values.beam_tilt_x = average_beam_tilt_x  / double(number_summed);
		average_values.beam_tilt_y = average_beam_tilt_y  / double(number_summed);
		average_values.image_shift_x = average_image_shift_x  / double(number_summed);
		average_values.image_shift_y = average_image_shift_y  / double(number_summed);
	}

	return average_values;
}

cisTEMParameterLine cisTEMParameters::ReturnParameterVariances(bool only_average_active)
{

	cisTEMParameterLine average_values;
	average_values = ReturnParameterAverages(only_average_active);

	cisTEMParameterLine variance_values;

	long 			variance_position_in_stack = 0;
	long			variance_image_is_active = 0;
	double		 	variance_psi = 0.0;
	double			variance_theta = 0.0;
	double			variance_phi = 0.0;
	double			variance_x_shift = 0.0;
	double			variance_y_shift = 0.0;
	double			variance_defocus_1 = 0.0;
	double			variance_defocus_2 = 0.0;
	double			variance_defocus_angle = 0.0;
	double			variance_phase_shift = 0.0;
	double			variance_occupancy = 0.0;
	double			variance_logp = 0;
	double			variance_sigma = 0.0;
	double 			variance_score = 0.0;
	double			variance_score_change = 0.0;
	double			variance_pixel_size = 0.0;
	double			variance_microscope_voltage_kv = 0.0;
	double			variance_microscope_spherical_aberration_mm = 0.0;
	double			variance_beam_tilt_x = 0.0;
	double			variance_beam_tilt_y = 0.0;
	double			variance_image_shift_x = 0.0;
	double			variance_image_shift_y = 0.0;

	long number_summed = 0;

	for (long counter = 0; counter < all_parameters.GetCount(); counter++)
	{
		if (ReturnImageIsActive(counter) >= 0 || only_average_active == false)
		{
			variance_position_in_stack += powf(ReturnPositionInStack(counter), 2);
			variance_image_is_active += powf(ReturnImageIsActive(counter), 2);
			variance_psi += powf(ReturnPsi(counter), 2);
			variance_theta += powf(ReturnTheta(counter), 2);
			variance_phi += powf(ReturnPhi(counter), 2);
			variance_x_shift += powf(ReturnXShift(counter), 2);
			variance_y_shift += powf(ReturnYShift(counter), 2);
			variance_defocus_1 += powf(ReturnDefocus1(counter), 2);
			variance_defocus_2 += powf(ReturnDefocus2(counter), 2);
			variance_defocus_angle += powf(ReturnDefocusAngle(counter), 2);
			variance_phase_shift += powf(ReturnPhaseShift(counter), 2);
			variance_occupancy += powf(ReturnOccupancy(counter), 2);
			variance_logp += powf(ReturnLogP(counter), 2);
			variance_sigma += powf(ReturnSigma(counter), 2);
			variance_score += powf(ReturnScore(counter), 2);
			variance_score_change += powf(ReturnScoreChange(counter), 2);
			variance_pixel_size += powf(ReturnPixelSize(counter), 2);
			variance_microscope_voltage_kv += powf(ReturnMicroscopekV(counter), 2);
			variance_microscope_spherical_aberration_mm += powf(ReturnMicroscopeCs(counter), 2);
			variance_beam_tilt_x += powf(ReturnBeamTiltX(counter), 2);
			variance_beam_tilt_y += powf(ReturnBeamTiltY(counter), 2);
			variance_image_shift_x += powf(ReturnImageShiftX(counter), 2);
			variance_image_shift_y += powf(ReturnImageShiftY(counter), 2);

			number_summed++;


		}

	}

	if (number_summed > 0)
	{
		variance_values.position_in_stack = variance_position_in_stack / double(number_summed);
		variance_values.image_is_active = variance_image_is_active / double(number_summed);
		variance_values.psi = variance_psi  / double(number_summed);
		variance_values.theta = variance_theta  / double(number_summed);
		variance_values.phi = variance_phi  / double(number_summed);
		variance_values.x_shift = variance_x_shift  / double(number_summed);
		variance_values.y_shift = variance_y_shift  / double(number_summed);
		variance_values.defocus_1 = variance_defocus_1  / double(number_summed);
		variance_values.defocus_2 = variance_defocus_2  / double(number_summed);
		variance_values.defocus_angle = variance_defocus_angle  / double(number_summed);
		variance_values.phase_shift = variance_phase_shift  / double(number_summed);
		variance_values.occupancy = variance_occupancy  / double(number_summed);
		variance_values.logp = variance_logp  / double(number_summed);
		variance_values.sigma = variance_sigma  / double(number_summed);
		variance_values.score = variance_score  / double(number_summed);
		variance_values.score_change = variance_score_change  / double(number_summed);
		variance_values.pixel_size = variance_pixel_size  / double(number_summed);
		variance_values.microscope_voltage_kv = variance_microscope_voltage_kv  / double(number_summed);
		variance_values.microscope_spherical_aberration_mm = variance_microscope_spherical_aberration_mm  / double(number_summed);
		variance_values.beam_tilt_x = variance_beam_tilt_x  / double(number_summed);
		variance_values.beam_tilt_y = variance_beam_tilt_y  / double(number_summed);
		variance_values.image_shift_x = variance_image_shift_x  / double(number_summed);
		variance_values.image_shift_y = variance_image_shift_y  / double(number_summed);
	}

	variance_values.position_in_stack -= powf(average_values.position_in_stack, 2);
	variance_values.image_is_active -= powf(average_values.image_is_active, 2);
	variance_values.psi -= powf(average_values.psi, 2);
	variance_values.theta -= powf(average_values.theta, 2);
	variance_values.phi -= powf(average_values.phi, 2);
	variance_values.x_shift -= powf(average_values.x_shift, 2);
	variance_values.y_shift -= powf(average_values.y_shift, 2);
	variance_values.defocus_1 -= powf(average_values.defocus_1, 2);
	variance_values.defocus_2 -= powf(average_values.defocus_2, 2);
	variance_values.defocus_angle -= powf(average_values.defocus_angle, 2);
	variance_values.phase_shift -= powf(average_values.phase_shift, 2);
	variance_values.occupancy -= powf(average_values.occupancy, 2);
	variance_values.logp -= powf(average_values.logp, 2);
	variance_values.sigma -= powf(average_values.sigma, 2);
	variance_values.score -= powf(average_values.score, 2);
	variance_values.score_change -= powf(average_values.score_change, 2);
	variance_values.pixel_size -= powf(average_values.pixel_size, 2);
	variance_values.microscope_voltage_kv -= powf(average_values.microscope_voltage_kv, 2);
	variance_values.microscope_spherical_aberration_mm -= powf(average_values.microscope_spherical_aberration_mm, 2);
	variance_values.beam_tilt_x -= powf(average_values.beam_tilt_x, 2);
	variance_values.beam_tilt_y -= powf(average_values.beam_tilt_y, 2);
	variance_values.image_shift_x -= powf(average_values.image_shift_x, 2);
	variance_values.image_shift_y -= powf(average_values.image_shift_y, 2);

	return variance_values;
}

double cisTEMParameters::ReturnAverageSigma(bool exclude_negative_film_numbers)
{
	double sum = 0;
	long number_summed = 0;

	for (long counter = 0; counter < all_parameters.GetCount(); counter++)
	{
		if (ReturnImageIsActive(counter) >= 0 || ! exclude_negative_film_numbers)
		{
			sum += ReturnSigma(counter);
			number_summed++;
		}
	}

	if (number_summed > 0) return sum / double(number_summed);
	else return 0.0;

}

double cisTEMParameters::ReturnAverageOccupancy(bool exclude_negative_film_numbers)
{
	double sum = 0;
	long number_summed = 0;

	for (long counter = 0; counter < all_parameters.GetCount(); counter++)
	{
		if (ReturnImageIsActive(counter) >= 0 || ! exclude_negative_film_numbers)
		{
			sum += ReturnOccupancy(counter);
			number_summed++;
		}
	}

	if (number_summed > 0) return sum / double(number_summed);
	else return 0.0;

}

void cisTEMParameters::RemoveSigmaOutliers(float wanted_standard_deviation, bool exclude_negative_film_numbers, bool reciprocal_square)
{
	MyDebugAssertTrue(wanted_standard_deviation > 0.0, "Invalid standard deviation");

	int line;
	int sum_i;
	double average = 0.0;
	double sum2 = 0.0;
	float std;
	float upper_threshold;
	float lower_threshold;
	float temp_float;

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_float = ReturnSigma(line);
			if (reciprocal_square && temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
			average += temp_float;
			sum2 += powf(temp_float, 2);
			sum_i++;
		}
	}

	if (sum_i > 0)
	{
		average /= sum_i;
		std = sum2 / sum_i - powf(average / sum_i, 2);
	}

	if (std > 0.0)
	{
		// Remove extreme outliers and recalculate std
		std = sqrtf(std);
		upper_threshold = average + 2.0 * wanted_standard_deviation * std;
		lower_threshold = average - 2.0 * wanted_standard_deviation * std;
//		wxPrintf("0: average, std, upper, lower = %g %g %g %g\n", float(average), std, upper_threshold, lower_threshold);
		average = 0.0;
		sum2 = 0.0;
		sum_i = 0;

		for (line = 0; line < all_parameters.GetCount(); line++)
		{
			if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
			{
				temp_float = ReturnSigma(line);
				if (reciprocal_square && temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
				if (temp_float <= upper_threshold && temp_float >= lower_threshold)
				{
					average += temp_float;
					sum2 += powf(temp_float, 2);
					sum_i++;
				}
			}
		}

		if (sum_i > 0)
		{
			average /= sum_i;
			std = sum2 / sum_i - powf(average / sum_i, 2);
		}

		// Now remove outliers according to (hopefully) more reasonable std
		std = sqrtf(std);

		upper_threshold = average + wanted_standard_deviation * std;
		lower_threshold = average - wanted_standard_deviation * std;
//		wxPrintf("1: average, std, upper, lower = %g %g %g %g\n", float(average), std, upper_threshold, lower_threshold);

		for (line = 0; line < all_parameters.GetCount(); line++)
		{
			if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
			{
				temp_float = ReturnSigma(line);

				if (reciprocal_square)
				{
					if (temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
					else temp_float = average;
					if (temp_float > upper_threshold) temp_float = upper_threshold;
					if (temp_float < lower_threshold) temp_float = lower_threshold;
					temp_float = sqrtf(1.0 / temp_float);
				}
				else
				{
					if (temp_float > upper_threshold) temp_float = upper_threshold;
					if (temp_float < lower_threshold) temp_float = lower_threshold;
				}

				all_parameters[line].sigma = temp_float;
			}
		}
	}


}

void cisTEMParameters::RemoveScoreOutliers(float wanted_standard_deviation, bool exclude_negative_film_numbers, bool reciprocal_square)
{
	MyDebugAssertTrue(wanted_standard_deviation > 0.0, "Invalid standard deviation");

	int line;
	int sum_i;
	double average = 0.0;
	double sum2 = 0.0;
	float std;
	float upper_threshold;
	float lower_threshold;
	float temp_float;

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_float = ReturnScore(line);
			if (reciprocal_square && temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
			average += temp_float;
			sum2 += powf(temp_float, 2);
			sum_i++;
		}
	}

	if (sum_i > 0)
	{
		average /= sum_i;
		std = sum2 / sum_i - powf(average / sum_i, 2);
	}

	if (std > 0.0)
	{
		// Remove extreme outliers and recalculate std
		std = sqrtf(std);
		upper_threshold = average + 2.0 * wanted_standard_deviation * std;
		lower_threshold = average - 2.0 * wanted_standard_deviation * std;
//		wxPrintf("0: average, std, upper, lower = %g %g %g %g\n", float(average), std, upper_threshold, lower_threshold);
		average = 0.0;
		sum2 = 0.0;
		sum_i = 0;

		for (line = 0; line < all_parameters.GetCount(); line++)
		{
			if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
			{
				temp_float = ReturnScore(line);
				if (reciprocal_square && temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
				if (temp_float <= upper_threshold && temp_float >= lower_threshold)
				{
					average += temp_float;
					sum2 += powf(temp_float, 2);
					sum_i++;
				}
			}
		}

		if (sum_i > 0)
		{
			average /= sum_i;
			std = sum2 / sum_i - powf(average / sum_i, 2);
		}

		// Now remove outliers according to (hopefully) more reasonable std
		std = sqrtf(std);

		upper_threshold = average + wanted_standard_deviation * std;
		lower_threshold = average - wanted_standard_deviation * std;
//		wxPrintf("1: average, std, upper, lower = %g %g %g %g\n", float(average), std, upper_threshold, lower_threshold);

		for (line = 0; line < all_parameters.GetCount(); line++)
		{
			if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
			{
				temp_float = ReturnScore(line);

				if (reciprocal_square)
				{
					if (temp_float > 0.0) temp_float = 1.0 / powf(temp_float, 2);
					else temp_float = average;
					if (temp_float > upper_threshold) temp_float = upper_threshold;
					if (temp_float < lower_threshold) temp_float = lower_threshold;
					temp_float = sqrtf(1.0 / temp_float);
				}
				else
				{
					if (temp_float > upper_threshold) temp_float = upper_threshold;
					if (temp_float < lower_threshold) temp_float = lower_threshold;
				}

				all_parameters[line].score = temp_float;
			}
		}
	}


}


void cisTEMParameters::CalculateDefocusDependence(bool exclude_negative_film_numbers)
{
	int line;
	double s = 0.0, sx = 0.0, sy = 0.0, sxx = 0.0, sxy = 0.0;
	double delta;

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			average_defocus = (ReturnDefocus1(line) + ReturnDefocus2(line)) / 2.0;
			s += ReturnOccupancy(line);
			sx += average_defocus * ReturnOccupancy(line);
			sy += ReturnScore(line) * ReturnOccupancy(line);
			sxx += powf(average_defocus,2) * ReturnOccupancy(line);
			sxy += average_defocus * ReturnScore(line) * ReturnOccupancy(line);
		}
	}
	average_defocus = sx / s;
	delta = s * sxx - powf(sx,2);
	defocus_coeff_a = (sxx * sy - sx * sxy) / delta;
	defocus_coeff_b = (s * sxy - sx * sy) / delta;
//	wxPrintf("average_defocus = %g, defocus_coeff_a = %g, defocus_coeff_b = %g\n", average_defocus, defocus_coeff_a, defocus_coeff_b);
}

void cisTEMParameters::AdjustScores(bool exclude_negative_film_numbers)
{
	int line;
	float defocus;

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			defocus = (ReturnDefocus1(line) + ReturnDefocus2(line)) / 2.0;
			if (defocus != 0.0f) all_parameters[line].score -= ReturnScoreAdjustment(defocus); // added 0 check for defocus sweep
		}
	}
}

float cisTEMParameters::ReturnScoreAdjustment(float defocus)
{
	MyDebugAssertTrue(average_defocus != 0.0 || defocus_coeff_b != 0.0, "Defocus coefficients not determined");

	return (defocus - average_defocus) * defocus_coeff_b;
}

float cisTEMParameters::ReturnScoreThreshold(float wanted_percentage, bool exclude_negative_film_numbers)
{

	int i;
	int line;
	int number_of_bins = 10000;
	float average_occ = 0.0;
	float sum_occ;
	float increment;
	float threshold;
	float percentage;
	float min, max;

	min = ReturnMinScore(exclude_negative_film_numbers);
	max = ReturnMaxScore(exclude_negative_film_numbers);

	average_occ = ReturnAverageOccupancy(exclude_negative_film_numbers);
	increment = (min - max) / (number_of_bins - 1);
	if (increment == 0.0) return min;

	//wxPrintf("min = %f, max = %f, increment = %f\n", min, max, increment);
	for (i = 0; i < number_of_bins; i++)
	{
		sum_occ = 0.0;
		threshold = float(i) * increment + max;

		for (line = 0; line < all_parameters.GetCount(); line++)
		{
			if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
			{
	 			if (ReturnScore(line) >= threshold) sum_occ += ReturnOccupancy(line);
			}
		}
		percentage = sum_occ / all_parameters.GetCount() / average_occ;

	//	wxPrintf("sum_occ = %f : threshold = %f\n", sum_occ, threshold);
		if (percentage >= wanted_percentage) break;
	}

	if (sum_occ == 0.0)
	{
		MyPrintWithDetails("Error: Number of particles selected = 0; please change score threshold\n");
		DEBUG_ABORT;
	}

	return threshold;
}

float cisTEMParameters::ReturnMinScore(bool exclude_negative_film_numbers)
{
	int line;
	float min;
	float temp_float;

	min = std::numeric_limits<float>::max();

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_float = ReturnScore(line);
			if (min > temp_float) min = temp_float;
		}
	}

	return min;
}

float cisTEMParameters::ReturnMaxScore(bool exclude_negative_film_numbers)
{
	int line;
	float max;
	float temp_float;

	max = std::numeric_limits<float>::min();

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_float = ReturnScore(line);
			if (max < temp_float) max = temp_float;
		}
	}

	return max;
}


int cisTEMParameters::ReturnMinPositionInStack(bool exclude_negative_film_numbers)
{
	int line;
	int min;
	int temp_int;

	min = std::numeric_limits<int>::max();

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_int = ReturnPositionInStack(line);
			if (min > temp_int) min = temp_int;
		}
	}

	return min;
}

int cisTEMParameters::ReturnMaxPositionInStack(bool exclude_negative_film_numbers)
{
	int line;
	int max;
	int temp_int;

	max = std::numeric_limits<int>::min();

	for (line = 0; line < all_parameters.GetCount(); line++)
	{
		if (ReturnImageIsActive(line) >= 0 || ! exclude_negative_film_numbers)
		{
			temp_int = ReturnPositionInStack(line);
			if (max < temp_int) max = temp_int;
		}
	}

	return max;
}
