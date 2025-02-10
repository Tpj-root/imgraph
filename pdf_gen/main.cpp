#include <cairo.h>
#include <cairo-pdf.h>
#include <iostream>
#include <cmath>  // For rounding

// Function to convert millimeters to points
double mm_to_points(double mm) {
    return mm * (72.0 / 25.4);  // Conversion factor
}

// Function to round a number to the nearest value
double round_to_nearest(double value) {
    return std::round(value);
}

// Function to draw a grid with a margin
void draw_grid_with_margin(cairo_t *cr, double width, double height, double cell_size, double margin) {
    // Set the margin area for drawing grid
    double x_start = margin;
    double y_start = margin;
    double x_end = width - margin;
    double y_end = height - margin;

    // Draw the grid
    for (double x = x_start; x <= x_end; x += cell_size) {
        // Draw every 10mm line in red with bold thickness
        if (fmod(x, mm_to_points(10)) < cell_size) {
            cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  // Red color
            cairo_set_line_width(cr, 1.5);  // Bold line
        } 
        // Draw every 1mm line in green
        else if (fmod(x, mm_to_points(1)) < cell_size) {
            cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  // Green color
            cairo_set_line_width(cr, 0.5);  // Normal line
        }

        cairo_move_to(cr, x, y_start);
        cairo_line_to(cr, x, y_end);
        cairo_stroke(cr);
    }

    for (double y = y_start; y <= y_end; y += cell_size) {
        // Draw every 10mm line in red with bold thickness
        if (fmod(y, mm_to_points(10)) < cell_size) {
            cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  // Red color
            cairo_set_line_width(cr, 1.5);  // Bold line
        } 
        // Draw every 1mm line in green
        else if (fmod(y, mm_to_points(1)) < cell_size) {
            cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  // Green color
            cairo_set_line_width(cr, 0.5);  // Normal line
        }

        cairo_move_to(cr, x_start, y);
        cairo_line_to(cr, x_end, y);
        cairo_stroke(cr);
    }
}


// Function to draw a border for visibility
void draw_border(cairo_t *cr, double width, double height, double margin) {
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);  // Black color for border
    cairo_set_line_width(cr, 2.0);  // Border line thickness
    cairo_rectangle(cr, margin, margin, width - 2 * margin, height - 2 * margin);
    cairo_stroke(cr);
}

int main() {
    // Define the PDF file to save
    const char *output_pdf = "grid_with_colored_lines.pdf";

    // Convert A4 dimensions from millimeters to points
    double width_mm = 210;  // A4 width in millimeters
    double height_mm = 297; // A4 height in millimeters

    double width = mm_to_points(width_mm);  // Convert width to points
    double height = mm_to_points(height_mm); // Convert height to points

    // Define the margin size in points (rounded)
    double margin_mm = 10;  // Margin size in millimeters
    double margin = mm_to_points(margin_mm); // Convert margin to points
    margin = round_to_nearest(margin); // Round margin to nearest value

    // Print debug information
    std::cout << "Page width (points): " << width << std::endl;
    std::cout << "Page height (points): " << height << std::endl;
    std::cout << "Margin (points): " << margin << std::endl;

    // Create the surface (PDF format, converted A4 size)
    cairo_surface_t *surface = cairo_pdf_surface_create(output_pdf, width, height);
    cairo_t *cr = cairo_create(surface);

    // Set a white background
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); // White color



    
    cairo_paint(cr);

    // Draw a border to ensure the page is not empty
    draw_border(cr, width, height, margin);

    // Draw a grid with cell size of 20 points inside the margin
    double cell_size = 20; // Cell size in points
    draw_grid_with_margin(cr, width, height, cell_size, margin);

    // Finish and save the PDF
    cairo_show_page(cr);

    // Clean up
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    std::cout << "PDF with grid and colored lines has been saved as " << output_pdf << std::endl;
    return 0;
}
