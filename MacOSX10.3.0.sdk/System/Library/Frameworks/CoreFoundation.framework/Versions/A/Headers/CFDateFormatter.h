/*	CFDateFormatter.h
	Copyright (c) 2003-2003, Apple, Inc. All rights reserved.
*/

#if !defined(__COREFOUNDATION_CFDATEFORMATTER__)
#define __COREFOUNDATION_CFDATEFORMATTER__ 1

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFDate.h>
#include <CoreFoundation/CFLocale.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct __CFDateFormatter *CFDateFormatterRef;

// CFDateFormatters are not thread-safe.  Do not use one from multiple threads!

CF_EXPORT
CFTypeID CFDateFormatterGetTypeID(void) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

typedef enum {	// date and time format styles
	kCFDateFormatterNoStyle = 0,
	kCFDateFormatterShortStyle = 1,
	kCFDateFormatterMediumStyle = 2,
	kCFDateFormatterLongStyle = 3,
	kCFDateFormatterFullStyle = 4
} CFDateFormatterStyle;

// The exact formatted result for these date and time styles depends on the
// locale, but generally:
//     Short is completely numeric, such as "12/13/52" or "3:30pm"
//     Medium is longer, such as "Jan 12, 1952"
//     Long is longer, such as "January 12, 1952" or "3:30:32pm"
//     Full is pretty complete; e.g. "Tuesday, April 12, 1952 AD" or "3:30:42pm PST"
// The specifications though are left fuzzy, in part simply because a user's
// preference choices may affect the output, and also the results may change
// from one OS release to another.  To produce an exactly formatted date you
// should not rely on styles and localization, but set the format string and
// use nothing but numbers.

CF_EXPORT
CFDateFormatterRef CFDateFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFDateFormatterStyle dateStyle, CFDateFormatterStyle timeStyle) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Returns a CFDateFormatter, localized to the given locale, which
	// will format dates to the given date and time styles.

CF_EXPORT
CFLocaleRef CFDateFormatterGetLocale(CFDateFormatterRef formatter) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
CFDateFormatterStyle CFDateFormatterGetDateStyle(CFDateFormatterRef formatter) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
CFDateFormatterStyle CFDateFormatterGetTimeStyle(CFDateFormatterRef formatter) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Get the properties with which the date formatter was created.

CF_EXPORT
CFStringRef CFDateFormatterGetFormat(CFDateFormatterRef formatter) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
void CFDateFormatterSetFormat(CFDateFormatterRef formatter, CFStringRef formatString) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Set the format description string of the date formatter.  This
	// overrides the style settings.  The format of the format string
	// is as defined by the ICU library, and is similar to that found
	// in C# (and Java I believe).  The date formatter starts with a
	// default format string defined by the style arguments with
	// which it was created.


CF_EXPORT
CFStringRef CFDateFormatterCreateStringWithDate(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFDateRef date) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
CFStringRef CFDateFormatterCreateStringWithAbsoluteTime(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFAbsoluteTime at) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Create a string representation of the given date or CFAbsoluteTime
	// using the current state of the date formatter.


CF_EXPORT
CFDateRef CFDateFormatterCreateDateFromString(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
Boolean CFDateFormatterGetAbsoluteTimeFromString(CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep, CFAbsoluteTime *atp) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Parse a string representation of a date using the current state
	// of the date formatter.  The range parameter specifies the range
	// of the string in which the parsing should occur in input, and on
	// output indicates the extent that was used; this parameter can
	// be NULL, in which case the whole string may be used.  The
	// return value indicates whether some date was computed and
	// (if atp is not NULL) stored at the location specified by atp.


CF_EXPORT
void CFDateFormatterSetProperty(CFDateFormatterRef formatter, CFStringRef key, CFTypeRef value) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

CF_EXPORT
CFTypeRef CFDateFormatterCopyProperty(CFDateFormatterRef formatter, CFStringRef key) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
	// Set and get various properties of the date formatter, the set of
	// which may be expanded in the future.

CF_EXPORT const CFStringRef kCFDateFormatterIsLenient AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;	// CFBoolean
CF_EXPORT const CFStringRef kCFDateFormatterTimeZone AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;		// CFTimeZone
CF_EXPORT const CFStringRef kCFDateFormatterCalendarName AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;	// CFString
CF_EXPORT const CFStringRef kCFDateFormatterDefaultFormat AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;	// CFString

CF_EXPORT const CFStringRef kCFGregorianCalendar AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

#if defined(__cplusplus)
}
#endif

#endif

#endif /* ! __COREFOUNDATION_CFDATEFORMATTER__ */

